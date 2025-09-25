# XINPUT_VIBRATION structure

## Description

Specifies motor speed levels for the vibration function of a controller.

## Members

### `wLeftMotorSpeed`

Speed of the left motor. Valid values are in the range 0 to 65,535. Zero signifies no motor use; 65,535 signifies 100 percent motor use.

### `wRightMotorSpeed`

Speed of the right motor. Valid values are in the range 0 to 65,535. Zero signifies no motor use; 65,535 signifies 100 percent motor use.

## Remarks

The left motor is the low-frequency rumble motor. The right motor is the high-frequency rumble motor. The two motors are not the same, and they create different vibration effects.

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XInput Structures](https://learn.microsoft.com/windows/desktop/xinput/structures)

[XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities)

[XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate)