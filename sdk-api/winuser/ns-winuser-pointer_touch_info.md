# POINTER_TOUCH_INFO structure

## Description

Defines basic touch information common to all pointer types.

## Members

### `pointerInfo`

Type: **[POINTER_INFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-pointer_info)**

An embedded [POINTER_INFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-pointer_info) header structure.

### `touchFlags`

Type: **[Touch Flags](https://learn.microsoft.com/windows/win32/inputmsg/touch-flags-constants)**

Currently none.

### `touchMask`

Type: **[Touch Mask](https://learn.microsoft.com/windows/win32/inputmsg/touch-mask-constants)**

Indicates which of the optional fields contain valid values. The member can be zero or any combination of the values from the [Touch Mask](https://learn.microsoft.com/windows/win32/inputmsg/touch-mask-constants) constants.

### `rcContact`

Type: **RECT**

The predicted screen coordinates of the contact area, in pixels.
By default, if the device does not report a contact area, this field defaults to a 0-by-0 rectangle centered around the pointer location.

The predicted value is based on the pointer position reported by the digitizer and the motion of the pointer. This correction can compensate for visual lag due to inherent delays in sensing and processing the pointer location on the digitizer. This is applicable to pointers of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type).

### `rcContactRaw`

Type: **RECT**

The raw screen coordinates of the contact area, in pixels. For adjusted screen coordinates, see **rcContact**.

### `orientation`

Type: **UINT32**

A pointer orientation, with a value between 0 and 359, where 0 indicates a touch pointer aligned with the x-axis and pointing from left to right; increasing values indicate degrees of rotation in the clockwise direction.

This field defaults to 0 if the device does not report orientation.

> [!NOTE]
> Some touchscreen devices that support orientation will only report half-range (0-180°) values, while other devices will only report full-range (0-359°) values.

### `pressure`

Type: **UINT32**

 A pen pressure normalized to a range between 0 and 1024. The default is 512.

## See also

[Structures](https://learn.microsoft.com/windows/win32/winrt/structures)