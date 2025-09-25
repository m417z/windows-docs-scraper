# KEYBOARD_ATTRIBUTES structure

## Description

Specifies the attributes of a keyboard.

## Members

### `KeyboardIdentifier`

Specifies the keyboard type and subtype in a KEYBOARD_ID structure:

```cpp
typedef struct _KEYBOARD_ID {
  UCHAR  Type;
  UCHAR  Subtype;
} KEYBOARD_ID, *PKEYBOARD_ID;
```

#### Type

Specifies the keyboard type.

| Value | Description |
|:-----:|------------------------------------------------------|
| 0x4 | Enhanced 101- or 102-key keyboards (and compatibles) |
| 0x7 | Japanese Keyboard |
| 0x8 | Korean Keyboard |
| 0x51 | Unknown type or HID keyboard |

#### Subtype

Specifies the keyboard subtype, which is a vendor-specific value.

### `KeyboardMode`

Specifies the scan code mode. See the [Remarks](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_attributes#remarks) section.

### `NumberOfFunctionKeys`

Specifies the number of function keys that a keyboard supports.

### `NumberOfIndicators`

Specifies the number of LED indicators that a keyboard supports.

### `NumberOfKeysTotal`

Specifies the number of keys that a keyboard supports.

### `InputDataQueueLength`

Specifies the size, in bytes, of the input data queue used by the keyboard port driver.

### `KeyRepeatMinimum`

Specifies the minimum possible value for the keyboard typematic rate and delay in a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### `KeyRepeatMaximum`

Specifies the maximum possible value for the keyboard typematic rate and delay in a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

## Remarks

This structure is used with a [IOCTL_KEYBOARD_QUERY_ATTRIBUTES IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes) request to return information about the attributes that a keyboard supports.

For more information about keyboard types, subtypes, scan code modes, and related keyboard layouts, see [Keyboard and mouse HID client drivers](https://learn.microsoft.com/windows-hardware/drivers/hid/keyboard-and-mouse-hid-client-drivers) in our drivers documentation.

More details can also be found in the *kbd.h*, *ntdd8042.h* and *ntddkbd.h* headers in the Windows SDK, the [USB HID to PS/2 Scan Code Translation Table](https://download.microsoft.com/download/1/6/1/161ba512-40e2-4cc9-843a-923143f3456c/translate.pdf) specification from Microsoft, and the [Keyboard Layout Samples](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/keyboard-layout-samples/).

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)

[IOCTL_KEYBOARD_SET_INDICATORS IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[IOCTL_KEYBOARD_SET_TYPEMATIC IOCTL](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)

[KEYBOARD_TYPEMATIC_PARAMETERS structure](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters)