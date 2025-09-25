# RAWINPUTDEVICELIST structure

## Description

Contains information about a raw input device.

## Members

### `hDevice`

Type: **HANDLE**

A handle to the raw input device.

### `dwType`

Type: **DWORD**

The type of device. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RIM_TYPEHID**<br><br>2 | The device is an HID that is not a keyboard and not a mouse. |
| **RIM_TYPEKEYBOARD**<br><br>1 | The device is a keyboard. |
| **RIM_TYPEMOUSE**<br><br>0 | The device is a mouse. |

## See also

**Conceptual**

[GetRawInputDeviceList](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdevicelist)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**