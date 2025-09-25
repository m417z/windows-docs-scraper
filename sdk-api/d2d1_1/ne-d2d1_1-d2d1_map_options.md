# D2D1_MAP_OPTIONS enumeration

## Description

Specifies how the memory to be mapped from the corresponding [ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1) should be treated.

## Constants

### `D2D1_MAP_OPTIONS_NONE:0`

### `D2D1_MAP_OPTIONS_READ:1`

Allow CPU Read access.

### `D2D1_MAP_OPTIONS_WRITE:2`

Allow CPU Write access.

### `D2D1_MAP_OPTIONS_DISCARD:4`

Discard the previous contents of the resource when it is mapped.

### `D2D1_MAP_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

The **D2D1_MAP_OPTIONS_READ** option can be used only if the bitmap was created with the **D2D1_BITMAP_OPTIONS_CPU_READ** flag.

These flags will be not be able to be used on bitmaps created by the [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext). However, the ID2D1SourceTransform will receive bitmaps for which these flags are valid.

**D2D1_MAP_OPTIONS_DISCARD** can only be used with **D2D1_MAP_OPTIONS_WRITE**. Both of these options are only available through the effect author API, not through the Direct2D rendering API.

## See also

[ID2D1Bitmap1::Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map)