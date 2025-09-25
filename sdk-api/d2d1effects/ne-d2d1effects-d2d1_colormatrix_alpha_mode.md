# D2D1_COLORMATRIX_ALPHA_MODE enumeration

## Description

The alpha mode of the output of the [Color matrix effect](https://learn.microsoft.com/windows/desktop/Direct2D/color-matrix).

## Constants

### `D2D1_COLORMATRIX_ALPHA_MODE_PREMULTIPLIED:1`

The effect un-premultiplies the input, applies the color matrix, and premultiplies the output.

### `D2D1_COLORMATRIX_ALPHA_MODE_STRAIGHT:2`

The effect applies the color matrix directly to the input, and doesn't premultiply the output.

### `D2D1_COLORMATRIX_ALPHA_MODE_FORCE_DWORD:0xffffffff`