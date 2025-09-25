# GetBitmapBits function

## Description

The **GetBitmapBits** function copies the bitmap bits of a specified device-dependent bitmap into a buffer.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits) function.

## Parameters

### `hbit` [in]

A handle to the device-dependent bitmap.

### `cb` [in]

The number of bytes to copy from the bitmap into the buffer.

### `lpvBits` [out]

A pointer to a buffer to receive the bitmap bits. The bits are stored as an array of byte values.

## Return value

If the function succeeds, the return value is the number of bytes copied to the buffer.

If the function fails, the return value is zero.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)