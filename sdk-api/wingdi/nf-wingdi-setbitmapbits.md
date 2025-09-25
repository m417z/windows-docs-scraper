# SetBitmapBits function

## Description

The **SetBitmapBits** function sets the bits of color data for a bitmap to the specified values.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) function.

## Parameters

### `hbm` [in]

A handle to the bitmap to be set. This must be a compatible bitmap (DDB).

### `cb` [in]

The number of bytes pointed to by the *lpBits* parameter.

### `pvBits` [in]

A pointer to an array of bytes that contain color data for the specified bitmap.

## Return value

If the function succeeds, the return value is the number of bytes used in setting the bitmap bits.

If the function fails, the return value is zero.

## Remarks

The array identified by *lpBits* must be WORD aligned.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetBitmapBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapbits)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)