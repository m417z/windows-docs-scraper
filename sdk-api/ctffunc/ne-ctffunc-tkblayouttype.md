# TKBLayoutType enumeration

## Description

Elements of the **TKBLayoutType** enumeration are passed by an IME in a call to [ITfFnGetPreferredTouchKeyboardLayout::GetLayout](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffngetpreferredtouchkeyboardlayout-getlayout) to specify the type of layout.

## Constants

### `TKBLT_UNDEFINED:0`

 Undefined. If specified, it will cause the layout to fallback to a classic layout.

### `TKBLT_CLASSIC:1`

The touch keyboard is to use a classic layout.

### `TKBLT_OPTIMIZED:2`

The touch keyboard is to use a touch-optimized layout.

## See also

[ITfFnGetPreferredTouchKeyboardLayout::GetLayout](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffngetpreferredtouchkeyboardlayout-getlayout)