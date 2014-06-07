require "PiE"
require "bindings"

function setup()
  print("In setup!")
end

function go(left, right)
    dev("motors/left").throttle = left
    dev("motors/right").throttle = right
end

function teleo()
  while wait{dev("joystick")} do
    go(dev("joystick").leftY, dev("joystick").rightY)
  end
end

function auto()

  go(100, 100) -- Full speed ahead!
  wait{second(0.5)}

  go(15, 15) -- Slow down.
  wait{second(1)}

  -- We should have hit the wall at this point.
  -- Backup and turn using the encoders.

  dev("motors/left").encoder.value = 0
  dev("motors/right").encoder.value = 0

  -- Backup
  go(-30, -15)

  -- Is this wait needed to prevent a race condition (reading the encoder value 
  -- in the loop below before it has been reset.)?
  wait{dev("motors/left"), dev("motors/right")}

  -- One way of doing it?
  --while wait{dev("motors/left").encoder,
             --dev("motors/right").encoder,
             --need="any"} do
      --ld = dev("motors/left").encoder.value
      --rd = dev("motors/right").encoder.value
  -- Another way?
  for ld, rd in wait_vals{dev("motors/left").encoder,
                          dev("motors/right").encoder,
                          need="any"} do
      -- What are the units of encoder ticks?
      if ld > 100 or rd > 20 then
        break
      end
  end
end
