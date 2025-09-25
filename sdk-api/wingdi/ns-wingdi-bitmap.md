# BITMAP structure

## Description

The **BITMAP** structure defines the type, width, height, color format, and bit values of a bitmap.

## Members

### `bmType`

The bitmap type. This member must be zero.

### `bmWidth`

The width, in pixels, of the bitmap. The width must be greater than zero.

### `bmHeight`

The height, in pixels, of the bitmap. The height must be greater than zero.

### `bmWidthBytes`

The number of bytes in each scan line. This value must be divisible by 2, because the system assumes that the bit values of a bitmap form an array that is word aligned.

### `bmPlanes`

The count of color planes.

### `bmBitsPixel`

The number of bits required to indicate the color of a pixel.

### `bmBits`

A pointer to the location of the bit values for the bitmap. The **bmBits** member must be a pointer to an array of character (1-byte) values.

## Remarks

The bitmap formats currently used are monochrome and color. The monochrome bitmap uses a one-bit, one-plane format. Each scan is a multiple of 16 bits.

Scans are organized as follows for a monochrome bitmap of height *n*:

``` syntax

    Scan 0
    Scan 1
    .
    .
    .
    Scan n-2
    Scan n-1

```

The pixels on a monochrome device are either black or white. If the corresponding bit in the bitmap is 1, the pixel is set to the foreground color; if the corresponding bit in the bitmap is zero, the pixel is set to the background color.

All devices that have the RC_BITBLT device capability support bitmaps. For more information, see [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps).

Each device has a unique color format. To transfer a bitmap from one device to another, use the [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits) and [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) functions.

## See also

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateBitmapIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmapindirect)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)