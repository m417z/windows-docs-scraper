# KEYBOARD_INDICATOR_PARAMETERS structure

## Description

KEYBOARD_INDICATOR_PARAMETERS specifies the state of a keyboard's indicator LEDs.

## Members

### `UnitId`

Specifies the unit number of a keyboard device. A keyboard device name has the format \Device\KeyboardPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\KeyboardPort0, has a unit number of zero, and a device, whose name is \Device\KeyboardPort1, has a unit number of one.

### `LedFlags`

Specifies a bitwise OR of zero or more of the following LED flags:

| LED Flag | Meaning |
| --- | --- |
| KEYBOARD_CAPS_LOCK_ON | CAPS LOCK LED is on. |
| KEYBOARD_LED_INJECTED | Used by a Terminal Server. |
| KEYBOARD_NUM_LOCK_ON | NUM LOCK LED is on. |
| KEYBOARD_SCROLL_LOCK_ON | SCROLL LOCK LED is on. |
| KEYBOARD_SHADOW | Used by a Terminal Server. |

## Remarks

This structure is used with [IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators) and [IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators) requests to query and set keyboard indicator LEDs.

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)

[IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)

[KEYBOARD_UNIT_ID_PARAMETER](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_unit_id_parameter)