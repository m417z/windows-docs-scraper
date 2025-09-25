# StretchDIB function

## Description

The **StretchDIB** function copies a device independent bitmap from one memory location to another and resizes the image to fit the destination rectangle.

## Parameters

### `biDst`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure that describes the destination bitmap.

### `lpDst`

Pointer to the memory buffer that will receive the copied pixel bits.

### `DstX`

X coordinate of the destination rectangle's origin.

### `DstY`

Y coordinate of the destination rectangle's origin.

### `DstXE`

Width, in pixels, of the destination rectangle.

### `DstYE`

Height, in pixels, of the destination rectangle.

### `biSrc`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure that describes the source bitmap.

### `lpSrc`

Pointer to the source bitmap data.

### `SrcX`

X coordinate of the source rectangle's origin.

### `SrcY`

Y coordinate of the source rectangle's origin.

### `SrcXE`

Width, in pixels, of the source rectangle.

### `SrcYE`

Height, in pixels, of the source rectangle.

## Remarks

The size of the destination buffer must be large enough to accommodate any alignment bytes at the end of each pixel row.

This function does nothing if *biSrc* and *biDst* have different values for *biBitCount* or if the value for *biSrc*. *biBitCount* does not equal 8, 16, or 24.

This function performs no dithering or other smoothing. Pixel values are merely dropped or duplicated on a line-by-line, column-by-column basis.

This function does not do any special processing based on pixel encoding except for calculating the number of bits per pixel. In particular this function will not generate correct results when pixels are encoded in groups of more than 1 pixel, as in the case of a YUV format where U and V are decimated and so are not represented equally in each pixel.

Before including Vfw.h, you must add the following line to your code:

```cpp

#define DRAWDIB_INCLUDE_STRETCHDIB

```