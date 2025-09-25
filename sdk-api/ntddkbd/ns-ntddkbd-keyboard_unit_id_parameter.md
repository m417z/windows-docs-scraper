# KEYBOARD_UNIT_ID_PARAMETER structure

## Description

KEYBOARD_UNIT_ID_PARAMETER specifies the unit ID that Kbdclass assigns to a keyboard.

## Members

### `UnitId`

Specifies the unit number of a keyboard device. A keyboard device name has the format \Device\KeyboardPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\KeyboardPort0, has a unit number of zero, and a device, whose name is \Device\KeyboardPort1, has a unit number of one.

## Remarks

Although this structure is used with IOCTL_KEYBOARD_QUERY_Xxx requests, Kbdclass does not use the **UnitId** value.

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)