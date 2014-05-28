function repr (val)
  function inner(tbl, indent)
    local sep = ", "
    local indent_text = ""
    local result = "{"
    if indent > 6 then
      local indent_text = string.rep(" ", indent)
      sep = ",\n" .. indent_text
      result = result .. "\n" .. indent_text
    end
    for k, v in pairs(tbl) do
      if type(k) ~= "string" then
        result = result .. repr(v) .. sep
      else
        formatting = k .. " = "
        if type(v) == "table" then
          result = result .. formatting .. inner(v, indent + 2)
        else
          result = result .. formatting .. repr(v) .. sep
        end
      end
    end
    result = result .. "}, "
    return result
  end
  if type(val) == "table" then
    return inner(val, 2)
  elseif type(val) == "string" then
    return "\"" .. val .. "\""
  elseif type(val) == "function" then
    return "<function>"
  end
  return "" .. val
end
