# KEYBOARD_INDICATOR_TRANSLATION structure

## Description

KEYBOARD_INDICATOR_TRANSLATION specifies a device-specific, variable length array of mappings between keyboard scan codes and LED indicators.

## Members

### `NumberOfIndicatorKeys`

Specifies the number of elements in the **IndicatorList** array.

### `IndicatorList`

Specifies a device-specific, variable-length array of INDICATOR_LIST structures.

```
typedef struct _INDICATOR_LIST {
  USHORT  MakeCode;
  USHORT  IndicatorFlags;
} INDICATOR_LIST, *PINDICATOR_LIST;
```

#### MakeCode

Specifies the make scan code that is generated when a key is pressed.

#### IndicatorFlags

Specifies the LED indicator that corresponds to the **MakeCode** scan code. For information about the flags, see the **LedFlags** member of the [KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters) structure.

## Remarks

This structure is used with an [IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation) request to obtain indicator translation information.

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)

[IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)

[KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters)