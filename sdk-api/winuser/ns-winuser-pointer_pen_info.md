# POINTER_PEN_INFO structure

## Description

Defines basic pen information common to all pointer types.

## Members

### `pointerInfo`

Type: **POINTER_INFO**

An embedded [POINTER_INFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-pointer_info) structure.

### `penFlags`

Type: **PEN_FLAGS**

The pen flag. This member can be zero or any reasonable combination of the values from the [Pen Flags](https://learn.microsoft.com/windows/win32/inputmsg/pen-flags-constants) constants.

### `penMask`

Type: **PEN_MASK**

The pen mask. This member can be zero or any reasonable combination of the values from the [Pen Mask](https://learn.microsoft.com/windows/win32/inputmsg/pen-mask-constants) constants.

### `pressure`

Type: **UINT32**

 A pen pressure normalized to a range between 0 and 1024. The default is 0 if the device does not report pressure.

### `rotation`

Type: **UINT32**

The clockwise rotation, or twist, of the pointer normalized in a range of 0 to 359.
The default is 0.

### `tiltX`

Type: **INT32**

The angle of tilt of the pointer along the x-axis in a range of -90 to +90, with a positive value indicating a tilt to the right.
The default is 0.

### `tiltY`

Type: **INT32**

The angle of tilt of the pointer along the y-axis in a range of -90 to +90, with a positive value indicating a tilt toward the user. The default is 0.

## Remarks

Applications can retrieve this information using the [GetPointerPenInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfo), [GetPointerFramePenInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframepeninfo), [GetPointerPenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfohistory) and [GetPointerFramePenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframepeninfohistory) API functions.

## See also

[Structures](https://learn.microsoft.com/windows/win32/inputmsg/structures)