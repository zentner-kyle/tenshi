function start_game()
  -- This should probably involve field control, etc.
  -- Actually, this function should probably be entirely implemented in C.
  -- Here for testing purposes. Would not be in the actual file. ;)
  require "PiE"
  require "student"
  local co = coroutine.create(function ()
    setup()

    auto()

    wait{second(20)}

    teleo()
  end)
  local run = true
  local err
  while run do
    run, err = coroutine.resume(co)
  end
  print(err)
end

start_game()
