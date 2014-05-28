require "util"

local devs = {}
local dev_bindings = {}
local unenumerated_devs = {}

local dev_name_should_be_string = "Need device name (a string)."

-- Returns the device associated with the name (possibly an address).

local function dev_raw(name, depth)
  if type(name) ~= "string" then
    error(dev_name_should_be_string, depth + 1)
  end
  if not(dev_bindings[name]) then
    -- What to do here?
    -- maybe the following
    -- local dev = dev_create(name, depth + 1)
    -- wait(dev_enumerate_raw(dev, depth + 1))
    -- return dev
    error('Could not find device ' .. name, depth + 1)
  end
  return dev_bindings[name]
end

-- If the device has not been enumerated yet?
-- If the device cannot be found?
function dev(name)
  return dev_raw(name, 2)
end

function dev_bind(new_name, old_name)
  if type(new_name) ~= "string" or
     type(old_name) ~= "string" then
     error(dev_name_should_be_string, 1)
  end
  local d = dev_raw(old_name, 1)
  dev_bindings[new_name] = d
end

local function dev_create_raw(address, expected_type, depth)
  local new_dev = {
    type = "unknown",
    address = address,
    expected_type = expected_type,
    listen = function (self)
      -- Something like this?
      -- This would be a C function setting a field associated with this thread?
      --piecs_listen(self.address)
    end,
    ignore = function (self)
      -- Something like this?
      -- This would be a C function setting a field associated with this thread?
      --piecs_ignore(self.address)
    end,
    event = function (self)
      return {
        value = 'dummy value',
      }
    end,
    encoder
  }
  function new_mock()
      local new_table = {"mock"}
      setmetatable(new_table, mock_mt)
      return new_table
  end
  local mock_mt = {
    __newindex = function(t, key, val)
      print(key .. " <- " .. val)
    end,
    __index = function(t, key)
      return new_mock()
    end,
    __call = function()
      return new_mock()
    end,
  }
  setmetatable(new_dev, mock_mt)
  table.insert(unenumerated_devs, new_dev)
  return new_dev
end

function dev_create(address, expected_type)
  return dev_create_raw(address, expected_type, 1)
end

local function make_virtual_source(type, event_function)
  return {
    type = type,
    virtual = true,
    listen = function () end,
    ignore = function () end,
    event = event_function,
  }
end

function second(n)
  -- Should this use game.time()?
  local start_time = os.time()
  return make_virtual_source("timer",
    function ()
      local time = os.time()
      if time - start_time > n then
        return time
      else
        return nil
      end
    end)
end

local function get_need_function(args, need, depth)
  if type(need) == "function" then
    return need
  end

  if need == "all" then
    need = #args
  elseif need == "any" then
    need = 1
  end

  if type(need) == "number" then
    return function (events)
      if #events > need then
        return true
      else
        return false
      end
    end
  end
  error('Could not make sense of need argument.', depth + 1)
end


-- Accepts a table of arguments
-- Sequence part of table should contain sources to wait for events from.
-- Key values include
-- need=<function> or number or "any" or "all"
function wait_raw(args, vals, depth)
  -- Default to requiring an event from each source.
  local need = get_need_function(args, args.need or "all", depth + 1)
  local srcs = args
  local events = {}
  local func = function ()
    for i,s in ipairs(srcs) do
      if not(s.listen) then
        print(repr(s))
      end
      s:listen()
    end

    coroutine.yield()

    for i,s in ipairs(srcs) do
      events[s] = s:event()
    end

    for i,s in ipairs(srcs) do
      s:ignore()
    end

    if need(events) then
      local vals = {}
      for s in ipairs(srcs) do
        -- Avoid having nil in the vals table
        vals[i] = events[s].value or 0
      end
      return unpack(vals)
    end
  end

  if not(vals) then
    -- Call it once so that wait() blocks
    -- This is used in while(wait{dev...}) and
    --
    -- dev(...).throttle = ...
    -- wait{dev(...)}
    --
    return func()
  else
    -- Return the function to be used in a for loop
    return func
  end
end

function wait(args)
  return wait_raw(args, false, 1)
end

function wait_vals(args)
  return wait_raw(args, true, 1)
end

function dev_enumerate()
  return make_virtual_source("enumeration",
  function ()
    for i,d in ipairs(unenumerated_devs) do
      devs[d.address] = d
      dev_bindings[d.address] = d
      unenumerated_devs[d] = nil
    end
    return {
      value = #devs,
    }
  end)
end
