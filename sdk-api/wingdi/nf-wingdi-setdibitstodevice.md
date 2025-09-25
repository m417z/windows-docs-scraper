# SetDIBitsToDevice function

## Description

The **SetDIBitsToDevice** function sets the pixels in the specified rectangle on the device that is associated with the destination device context using color data from a DIB, JPEG, or PNG image.

## Parameters

### `hdc` [in]

A handle to the device context.

### `xDest` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `yDest` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `w` [in]

The width, in logical units, of the image.

### `h` [in]

The height, in logical units, of the image.

### `xSrc` [in]

The x-coordinate, in logical units, of the lower-left corner of the image.

### `ySrc` [in]

The y-coordinate, in logical units, of the lower-left corner of the image.

### `StartScan` [in]

The starting scan line in the image.

### `cLines` [in]

The number of DIB scan lines contained in the array pointed to by the *lpvBits* parameter.

### `lpvBits` [in]

A pointer to the color data stored as an array of bytes. For more information, see the following Remarks section.

### `lpbmi` [in]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that contains information about the DIB.

### `ColorUse` [in]

Indicates whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contains explicit red, green, blue (RGB) values or indexes into a palette. For more information, see the following Remarks section.

The *fuColorUse* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | The color table consists of an array of 16-bit indexes into the currently selected logical palette. |
| **DIB_RGB_COLORS** | The color table contains literal RGB values. |

## Return value

If the function succeeds, the return value is the number of scan lines set.

If zero scan lines are set (such as when *dwHeight* is 0) or the function fails, the function returns zero.

If the driver cannot support the JPEG or PNG file image passed to **SetDIBitsToDevice**, the function will fail and return GDI_ERROR. If failure does occur, the application must fall back on its own JPEG or PNG support to decompress the image into a bitmap, and then pass the bitmap to **SetDIBitsToDevice**.

## Remarks

Optimal bitmap drawing speed is obtained when the bitmap bits are indexes into the system palette.

Applications can retrieve the system palette colors and indexes by calling the [GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries) function. After the colors and indexes are retrieved, the application can create the DIB. For more information about the system palette, see [Colors](https://learn.microsoft.com/windows/desktop/gdi/colors).

The scan lines must be aligned on a **DWORD** except for RLE-compressed bitmaps.

The origin of a bottom-up DIB is the lower-left corner of the bitmap; the origin of a top-down DIB is the upper-left corner.

To reduce the amount of memory required to set bits from a large DIB on a device surface, an application can band the output by repeatedly calling **SetDIBitsToDevice**, placing a different portion of the bitmap into the *lpvBits* array each time. The values of the *uStartScan* and *cScanLines* parameters identify the portion of the bitmap contained in the *lpvBits* array.

The **SetDIBitsToDevice** function returns an error if it is called by a process that is running in the background while a full-screen MS-DOS session runs in the foreground.

* If the **biCompression** member of [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) is BI_JPEG or BI_PNG, *lpvBits* points to a buffer containing a JPEG or PNG image. The **biSizeImage** member of specifies the size of the buffer. The *fuColorUse* parameter must be set to DIB_RGB_COLORS.
* To ensure proper metafile spooling while printing, applications must call the CHECKJPEGFORMAT or CHECKPNGFORMAT escape to verify that the printer recognizes the JPEG or PNG image, respectively, before calling **SetDIBitsToDevice**.

**ICM:** Color management is performed if color management has been enabled with a call to [SetICMMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmmode) with the *iEnableICM* parameter set to ICM_ON. If the bitmap specified by *lpbmi* has a [BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header) that specifies the gamma and endpoints members, or a [BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header) that specifies either the gamma and endpoints members or the profileData and profileSize members, then the call treats the bitmap's pixels as being expressed in the color space described by those members, rather than in the device context's source color space.

#### Examples

For an example, see [Testing a Printer for JPEG or PNG Support](https://learn.microsoft.com/windows/desktop/gdi/testing-a-printer-for-jpeg-or-png-support).

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)