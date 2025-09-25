# StretchDIBits function

## Description

The **StretchDIBits** function copies the color data for a rectangle of pixels in a DIB, JPEG, or PNG image to the specified destination rectangle. If the destination rectangle is larger than the source rectangle, this function stretches the rows and columns of color data to fit the destination rectangle. If the destination rectangle is smaller than the source rectangle, this function compresses the rows and columns by using the specified raster operation.

## Parameters

### `hdc` [in]

A handle to the destination device context.

### `xDest` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `yDest` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `DestWidth` [in]

The width, in logical units, of the destination rectangle.

### `DestHeight` [in]

The height, in logical units, of the destination rectangle.

### `xSrc` [in]

The x-coordinate, in pixels, of the source rectangle in the image.

### `ySrc` [in]

The y-coordinate, in pixels, of the source rectangle in the image.

### `SrcWidth` [in]

The width, in pixels, of the source rectangle in the image.

### `SrcHeight` [in]

The height, in pixels, of the source rectangle in the image.

### `lpBits` [in]

A pointer to the image bits, which are stored as an array of bytes. For more information, see the Remarks section.

### `lpbmi` [in]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that contains information about the DIB.

### `iUsage` [in]

Specifies whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure was provided and, if so, whether **bmiColors** contains explicit red, green, blue (RGB) values or indexes. The *iUsage* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | The array contains 16-bit indexes into the logical palette of the source device context. |
| **DIB_RGB_COLORS** | The color table contains literal RGB values. |

For more information, see the Remarks section.

### `rop` [in]

A raster-operation code that specifies how the source pixels, the destination device context's current brush, and the destination pixels are to be combined to form the new image. For a list of some common raster operation codes, see [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt).

## Return value

If the function succeeds, the return value is the number of scan lines copied. Note that this value can be negative for mirrored content.

If the function fails, or no scan lines are copied, the return value is 0.

If the driver cannot support the JPEG or PNG file image passed to **StretchDIBits**, the function will fail and return GDI_ERROR. If failure does occur, the application must fall back on its own JPEG or PNG support to decompress the image into a bitmap, and then pass the bitmap to **StretchDIBits**.

## Remarks

The origin of a bottom-up DIB is the lower-left corner; the origin of a top-down DIB is the upper-left corner.

**StretchDIBits** creates a mirror image of a bitmap if the signs of the *nSrcWidth* and *nDestWidth* parameters, or if the *nSrcHeight* and *nDestHeight* parameters differ. If *nSrcWidth* and *nDestWidth* have different signs, the function creates a mirror image of the bitmap along the x-axis. If *nSrcHeight* and *nDestHeight* have different signs, the function creates a mirror image of the bitmap along the y-axis.

**StretchDIBits** creates a top-down image if the sign of the **biHeight** member of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure for the DIB is negative. For a code example, see [Sizing a JPEG or PNG Image](https://learn.microsoft.com/windows/desktop/gdi/sizing-a-jpeg-or-png-image).

This function allows a JPEG or PNG image to be passed as the source image. How each parameter is used remains the same, except:

* If the **biCompression** member of [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) is BI_JPEG or BI_PNG, *lpBits* points to a buffer containing a JPEG or PNG image, respectively. The **biSizeImage** member of the **BITMAPINFOHEADER** structure specifies the size of the buffer. The *iUsage* parameter must be set to DIB_RGB_COLORS. The *dwRop* parameter must be set to SRCCOPY.
* To ensure proper metafile spooling while printing, applications must call the CHECKJPEGFORMAT or CHECKPNGFORMAT escape to verify that the printer recognizes the JPEG or PNG image, respectively, before calling **StretchDIBits**.

**ICM:** Color management is performed if color management has been enabled with a call to [SetICMMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmmode) with the *iEnableICM* parameter set to ICM_ON. If the bitmap specified by *lpBitsInfo* has a [BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header) that specifies the gamma and endpoints members, or a [BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header) that specifies either the gamma and endpoints members or the profileData and profileSize members, then the call treats the bitmap's pixels as being expressed in the color space described by those members, rather than in the device context's source color space.

#### Examples

For an example, see [Sizing a JPEG or PNG Image](https://learn.microsoft.com/windows/desktop/gdi/sizing-a-jpeg-or-png-image).

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[SetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapmode)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)