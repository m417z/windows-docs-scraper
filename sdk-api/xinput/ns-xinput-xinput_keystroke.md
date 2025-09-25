# XINPUT_KEYSTROKE structure

## Description

Specifies keystroke data returned by [XInputGetKeystroke](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetkeystroke).

## Members

### `VirtualKey`

Virtual-key code of the key, button, or stick movement. See XInput.h for a list of valid virtual-key (VK_xxx) codes. Also, see Remarks.

### `Unicode`

This member is unused and the value is zero.

### `Flags`

Flags that indicate the keyboard state at the time of the input event. This member can be any combination of the following flags:

| Value | Description |
| --- | --- |
| XINPUT_KEYSTROKE_KEYDOWN | The key was pressed. |
| XINPUT_KEYSTROKE_KEYUP | The key was released. |
| XINPUT_KEYSTROKE_REPEAT | A repeat of a held key. |

### `UserIndex`

Index of the signed-in gamer associated with the device. Can be a value in the range 0–3.

### `HidCode`

HID code corresponding to the input. If there is no corresponding HID code, this value is zero.

## Remarks

Future devices may return HID codes and virtual key values that are not supported on current devices, and are currently undefined. Applications should ignore these unexpected values.

A *virtual-key* code is a byte value that represents a particular physical key on the keyboard, not the character or characters (possibly none) that the key can be mapped to based on keyboard state. The keyboard state at the time a virtual key is pressed modifies the character reported. For example, VK_4 might represent a "4" or a "$", depending on the state of the SHIFT key.

A reported keyboard event includes the virtual key that caused the event, whether the key was pressed or released (or is repeating), and the state of the keyboard at the time of the event. The keyboard state includes information about whether any CTRL, ALT, or SHIFT keys are down.

If the keyboard event represents an Unicode character (for example, pressing the "A" key), the *Unicode* member will contain that character. Otherwise, *Unicode* will contain the value zero.

The valid virtual-key (VK_xxx) codes are defined in XInput.h. In addition to codes that indicate key presses, the following codes indicate controller input.

| Value | Description |
| --- | --- |
| VK_PAD_A | **A** button |
| VK_PAD_B | **B** button |
| VK_PAD_X | **X** button |
| VK_PAD_Y | **Y** button |
| VK_PAD_RSHOULDER | Right shoulder button |
| VK_PAD_LSHOULDER | Left shoulder button |
| VK_PAD_LTRIGGER | Left trigger |
| VK_PAD_RTRIGGER | Right trigger |
| VK_PAD_DPAD_UP | Directional pad up |
| VK_PAD_DPAD_DOWN | Directional pad down |
| VK_PAD_DPAD_LEFT | Directional pad left |
| VK_PAD_DPAD_RIGHT | Directional pad right |
| VK_PAD_START | **START** button |
| VK_PAD_BACK | **BACK** button |
| VK_PAD_LTHUMB_PRESS | Left thumbstick click |
| VK_PAD_RTHUMB_PRESS | Right thumbstick click |
| VK_PAD_LTHUMB_UP | Left thumbstick up |
| VK_PAD_LTHUMB_DOWN | Left thumbstick down |
| VK_PAD_LTHUMB_RIGHT | Left thumbstick right |
| VK_PAD_LTHUMB_LEFT | Left thumbstick left |
| VK_PAD_LTHUMB_UPLEFT | Left thumbstick up and left |
| VK_PAD_LTHUMB_UPRIGHT | Left thumbstick up and right |
| VK_PAD_LTHUMB_DOWNRIGHT | Left thumbstick down and right |
| VK_PAD_LTHUMB_DOWNLEFT | Left thumbstick down and left |
| VK_PAD_RTHUMB_UP | Right thumbstick up |
| VK_PAD_RTHUMB_DOWN | Right thumbstick down |
| VK_PAD_RTHUMB_RIGHT | Right thumbstick right |
| VK_PAD_RTHUMB_LEFT | Right thumbstick left |
| VK_PAD_RTHUMB_UPLEFT | Right thumbstick up and left |
| VK_PAD_RTHUMB_UPRIGHT | Right thumbstick up and right |
| VK_PAD_RTHUMB_DOWNRIGHT | Right thumbstick down and right |
| VK_PAD_RTHUMB_DOWNLEFT | Right thumbstick down and left |

## See also

[XInputGetKeystroke](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetkeystroke)