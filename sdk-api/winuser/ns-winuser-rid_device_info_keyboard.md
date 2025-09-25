# RID_DEVICE_INFO_KEYBOARD structure

## Description

Defines the raw input data coming from the specified keyboard.

## Members

### `dwType`

Type: **DWORD**

The type of keyboard. See [Remarks](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rid_device_info_keyboard#remarks).

| Value | Description |
|:-----:|------------------------------------------------------|
| 0x4 | Enhanced 101- or 102-key keyboards (and compatibles) |
| 0x7 | Japanese Keyboard |
| 0x8 | Korean Keyboard |
| 0x51 | Unknown type or HID keyboard |

### `dwSubType`

Type: **DWORD**

The vendor-specific subtype of the keyboard. See [Remarks](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rid_device_info_keyboard#remarks).

### `dwKeyboardMode`

Type: **DWORD**

The scan code mode. Usually 1, which means that *Scan Code Set 1* is used. See [Keyboard Scan Code Specification](https://download.microsoft.com/download/1/6/1/161ba512-40e2-4cc9-843a-923143f3456c/scancode.doc).

### `dwNumberOfFunctionKeys`

Type: **DWORD**

The number of function keys on the keyboard.

### `dwNumberOfIndicators`

Type: **DWORD**

The number of LED indicators on the keyboard.

### `dwNumberOfKeysTotal`

Type: **DWORD**

The total number of keys on the keyboard.

## Remarks

For information about keyboard types, subtypes, scan code modes, and related keyboard layouts, see the documentation in *kbd.h*, *ntdd8042.h* and *ntddkbd.h* headers in Windows SDK, and the [Keyboard Layout Samples](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/keyboard-layout-samples/).

## See also

**Conceptual**

[RID_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rid_device_info)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**

[KEYBOARD_ATTRIBUTES structure](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_attributes)