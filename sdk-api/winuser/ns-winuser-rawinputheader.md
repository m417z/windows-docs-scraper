# RAWINPUTHEADER structure

## Description

Contains the header information that is part of the raw input data.

## Members

### `dwType`

Type: **DWORD**

The type of raw input. It can be one of the following values:

| Value | Meaning |
|-------------------------|---------------------------------------------------------------------|
| **RIM\_TYPEMOUSE** 0 | Raw input comes from the mouse. |
| **RIM\_TYPEKEYBOARD** 1 | Raw input comes from the keyboard. |
| **RIM\_TYPEHID** 2 | Raw input comes from some device that is not a keyboard or a mouse. |

### `dwSize`

Type: **DWORD**

The size, in bytes, of the entire input packet of data. This includes [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) plus possible extra input reports in the [RAWHID](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawhid) variable length array.

### `hDevice`

Type: **HANDLE**

A handle to the device generating the raw input data.

### `wParam`

Type: **WPARAM**

The value passed in the *wParam* parameter of the [WM_INPUT](https://learn.microsoft.com/windows/win32/inputdev/wm-input) message.

## Remarks

To get more information on the device, use **hDevice** in a call to [GetRawInputDeviceInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getrawinputdeviceinfoa). **hDevice** can be zero if an input is received from a precision touchpad.

## See also

**Conceptual**

[GetRawInputDeviceInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getrawinputdeviceinfoa)

[RAWINPUT structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput)

[RAWKEYBOARD structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawkeyboard)

[RAWMOUSE structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawmouse)

[RAWHID structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawhid)

[Raw Input](https://learn.microsoft.com/windows/win32/inputdev/raw-input)

**Reference**

[WM_INPUT](https://learn.microsoft.com/windows/win32/inputdev/wm-input)