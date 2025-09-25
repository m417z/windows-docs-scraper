# KEYBOARD_TYPEMATIC_PARAMETERS structure

## Description

KEYBOARD_TYPEMATIC_PARAMETERS specifies a keyboard's typematic settings.

## Members

### `UnitId`

Specifies the unit number of a keyboard device. A keyboard device name has the format \Device\KeyboardPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\KeyboardPort0, has a unit number of zero, and a device, whose name is \Device\KeyboardPort1, has a unit number of one.

### `Rate`

Specifies the rate at which character output from a keyboard repeats, in characters per second, after a key is pressed and continuously held down. The minimum possible value is KEYBOARD_TYPEMATIC_RATE_MINIMUM and the maximum possible value is KEYBOARD_TYPEMATIC_RATE_MAXIMUM. The default value is KEYBOARD_TYPEMATIC_RATE_DEFAULT.

### `Delay`

Specifies the amount of time that must elapse, in milliseconds, after a key is pressed and continuously held down, before the character output from a keyboard begins to repeat. The minimum possible delay is KEYBOARD_TYPEMATIC_DELAY_MINIMUM and the maximum possible delay is KEYBOARD_TYPEMATIC_DELAY_MAXIMUM. The default value is KEYBOARD_TYPEMATIC_DELAY_DEFAULT.

## Remarks

This structure is used with [IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic) and [IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic) requests to query and set a keyboard's typematic settings.

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)

[IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)

[KEYBOARD_UNIT_ID_PARAMETER](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_unit_id_parameter)