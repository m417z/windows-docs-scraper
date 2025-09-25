# WICBitmapDitherType enumeration

## Description

Specifies the type of dither algorithm to apply when converting between image formats.

## Constants

### `WICBitmapDitherTypeNone:0`

A solid color algorithm without dither.

### `WICBitmapDitherTypeSolid:0`

A solid color algorithm without dither.

### `WICBitmapDitherTypeOrdered4x4:0x1`

A 4x4 ordered dither algorithm.

### `WICBitmapDitherTypeOrdered8x8:0x2`

An 8x8 ordered dither algorithm.

### `WICBitmapDitherTypeOrdered16x16:0x3`

A 16x16 ordered dither algorithm.

### `WICBitmapDitherTypeSpiral4x4:0x4`

A 4x4 spiral dither algorithm.

### `WICBitmapDitherTypeSpiral8x8:0x5`

An 8x8 spiral dither algorithm.

### `WICBitmapDitherTypeDualSpiral4x4:0x6`

A 4x4 dual spiral dither algorithm.

### `WICBitmapDitherTypeDualSpiral8x8:0x7`

An 8x8 dual spiral dither algorithm.

### `WICBitmapDitherTypeErrorDiffusion:0x8`

An error diffusion algorithm.

### `WICBITMAPDITHERTYPE_FORCE_DWORD:0x7fffffff`

## See also

[Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicformatconverter-initialize)