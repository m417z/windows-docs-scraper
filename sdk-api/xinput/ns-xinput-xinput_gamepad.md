# XINPUT_GAMEPAD structure

## Description

Describes the current state of the controller.

## Members

### `wButtons`

Bitmask of the device digital buttons, as follows. A set bit indicates that the corresponding button is pressed.

| Device button | Bitmask |
| --- | --- |
| XINPUT_GAMEPAD_DPAD_UP | 0x0001 |
| XINPUT_GAMEPAD_DPAD_DOWN | 0x0002 |
| XINPUT_GAMEPAD_DPAD_LEFT | 0x0004 |
| XINPUT_GAMEPAD_DPAD_RIGHT | 0x0008 |
| XINPUT_GAMEPAD_START | 0x0010 |
| XINPUT_GAMEPAD_BACK | 0x0020 |
| XINPUT_GAMEPAD_LEFT_THUMB | 0x0040 |
| XINPUT_GAMEPAD_RIGHT_THUMB | 0x0080 |
| XINPUT_GAMEPAD_LEFT_SHOULDER | 0x0100 |
| XINPUT_GAMEPAD_RIGHT_SHOULDER | 0x0200 |
| XINPUT_GAMEPAD_A | 0x1000 |
| XINPUT_GAMEPAD_B | 0x2000 |
| XINPUT_GAMEPAD_X | 0x4000 |
| XINPUT_GAMEPAD_Y | 0x8000 |

Bits that are set but not defined above are reserved, and their state is undefined.

### `bLeftTrigger`

The current value of the left trigger analog control. The value is between 0 and 255.

### `bRightTrigger`

The current value of the right trigger analog control. The value is between 0 and 255.

### `sThumbLX`

Left thumbstick x-axis value. Each of the thumbstick axis members is a signed value between -32768 and 32767 describing the position of the thumbstick. A value of 0 is centered. Negative values signify down or to the left. Positive values signify up or to the right. The constants XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE or XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE can be used as a positive and negative value to filter a thumbstick input.

### `sThumbLY`

Left thumbstick y-axis value. The value is between -32768 and 32767.

### `sThumbRX`

Right thumbstick x-axis value. The value is between -32768 and 32767.

### `sThumbRY`

Right thumbstick y-axis value. The value is between -32768 and 32767.

## Remarks

This structure is used by the [XINPUT_STATE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_state) structure when polling for changes in the state of the controller.

The specific mapping of button to game function varies depending on the game type.

The constant XINPUT_GAMEPAD_TRIGGER_THRESHOLD may be used as the value which *bLeftTrigger* and *bRightTrigger* must be greater than to register as pressed. This is optional, but often desirable. Controller buttons do not manifest crosstalk.

## See also

[XINPUT_STATE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_state)

[XInput Structures](https://learn.microsoft.com/windows/desktop/xinput/structures)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)