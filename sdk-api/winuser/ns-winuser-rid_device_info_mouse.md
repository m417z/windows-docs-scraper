# RID_DEVICE_INFO_MOUSE structure

## Description

Defines the raw input data coming from the specified mouse.

## Members

### `dwId`

Type: **DWORD**

The bitfield of the mouse device identification properties:

| Value | ntddmou.h constant | Description |
|:------:|----------------------------|----------------------------------------------------------------------------------------|
| 0x0080 | MOUSE\_HID\_HARDWARE | [HID mouse](https://learn.microsoft.com/windows-hardware/drivers/hid/keyboard-and-mouse-hid-client-drivers) |
| 0x0100 | WHEELMOUSE\_HID\_HARDWARE | [HID wheel mouse](https://learn.microsoft.com/windows-hardware/drivers/hid/keyboard-and-mouse-hid-client-drivers) |
| 0x8000 | HORIZONTAL\_WHEEL\_PRESENT | Mouse with horizontal wheel |

### `dwNumberOfButtons`

Type: **DWORD**

The number of buttons for the mouse.

### `dwSampleRate`

Type: **DWORD**

The number of data points per second. This information may not be applicable for every mouse device.

### `fHasHorizontalWheel`

Type: **BOOL**

**TRUE** if the mouse has a wheel for horizontal scrolling; otherwise, **FALSE**.

**Windows XP:** This member is only supported starting with Windows Vista.

## Remarks

For the mouse, the Usage Page is 1 and the Usage is 2.

## See also

**Conceptual**

[RID_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**