# RGBQUAD structure

## Description

The **RGBQUAD** structure describes a color consisting of relative intensities of red, green, and blue.

## Members

### `rgbBlue`

The intensity of blue in the color.

### `rgbGreen`

The intensity of green in the color.

### `rgbRed`

The intensity of red in the color.

### `rgbReserved`

This member is reserved and must be zero.

## Remarks

The **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure consists of an array of **RGBQUAD** structures.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[SetDIBitsToDevice](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibitstodevice)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)