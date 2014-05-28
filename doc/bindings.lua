
-- This file (would be) auto generated!
-- Do not edit it unless you know what you"re doing ;).


require "PiE" 

function bind_devices()
  -- Is this even necessary? We could auto-create objects for all enumerated 
  -- devices.
  dev_create("0x51455a5aff138730")
  dev_create("0x6d2ea9c9bcb5b5b9")
  wait{dev_enumerate()}
  dev_bind("motors/left", "0x51455a5aff138730")
  dev_bind("motors/right", "0x6d2ea9c9bcb5b5b9")
end

-- Should this automatically be called here, or do we require the students to 
-- call it in setup()?
--bind_devices()
