# RID_DEVICE_INFO structure

## Description

Defines the raw input data coming from any device.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of the **RID_DEVICE_INFO** structure.

### `dwType`

Type: **DWORD**

The type of raw input data. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RIM_TYPEMOUSE**<br><br>0 | Data comes from a mouse. |
| **RIM_TYPEKEYBOARD**<br><br>1 | Data comes from a keyboard. |
| **RIM_TYPEHID**<br><br>2 | Data comes from an HID that is not a keyboard or a mouse. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.mouse`

Type: **[RID_DEVICE_INFO_MOUSE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_mouse)**

If **dwType** is **RIM_TYPEMOUSE**, this is the [RID_DEVICE_INFO_MOUSE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_mouse) structure that defines the mouse.

### `DUMMYUNIONNAME.keyboard`

Type: **[RID_DEVICE_INFO_KEYBOARD](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_keyboard)**

If **dwType** is **RIM_TYPEKEYBOARD**, this is the [RID_DEVICE_INFO_KEYBOARD](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_keyboard) structure that defines the keyboard.

### `DUMMYUNIONNAME.hid`

Type: **[RID_DEVICE_INFO_HID](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_hid)**

If **dwType** is **RIM_TYPEHID**, this is the [RID_DEVICE_INFO_HID](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_hid) structure that defines the HID device.

## See also

**Conceptual**

[GetRawInputDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdeviceinfoa)

[RID_DEVICE_INFO_HID](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_hid)

[RID_DEVICE_INFO_KEYBOARD](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_keyboard)

[RID_DEVICE_INFO_MOUSE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info_mouse)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**