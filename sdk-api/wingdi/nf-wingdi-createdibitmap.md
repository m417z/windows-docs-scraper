# CreateDIBitmap function

## Description

The **CreateDIBitmap** function creates a compatible bitmap (DDB) from a DIB and, optionally, sets the bitmap bits.

## Parameters

### `hdc` [in]

A handle to a device context.

### `pbmih` [in]

A pointer to a bitmap information header structure, [BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header).

If *fdwInit* is CBM_INIT, the function uses the bitmap information header structure to obtain the desired width and height of the bitmap as well as other information. Note that a positive value for the height indicates a bottom-up DIB while a negative value for the height indicates a top-down DIB. Calling **CreateDIBitmap** with *fdwInit* as CBM_INIT is equivalent to calling the [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap) function to create a DDB in the format of the device and then calling the [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) function to translate the DIB bits to the DDB.

### `flInit` [in]

Specifies how the system initializes the bitmap bits. The following value is defined.

| Value | Meaning |
| --- | --- |
| **CBM_INIT** | If this flag is set, the system uses the data pointed to by the *lpbInit* and *lpbmi* parameters to initialize the bitmap bits.<br><br>If this flag is clear, the data pointed to by those parameters is not used. |

If *fdwInit* is zero, the system does not initialize the bitmap bits.

### `pjBits` [in]

A pointer to an array of bytes containing the initial bitmap data. The format of the data depends on the **biBitCount** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure to which the *lpbmi* parameter points.

### `pbmi` [in]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that describes the dimensions and color format of the array pointed to by the *lpbInit* parameter.

### `iUsage` [in]

Specifies whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure was initialized and, if so, whether **bmiColors** contains explicit red, green, blue (RGB) values or palette indexes. The *fuUsage* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | A color table is provided and consists of an array of 16-bit indexes into the logical palette of the device context into which the bitmap is to be selected. |
| **DIB_RGB_COLORS** | A color table is provided and contains literal RGB values. |

## Return value

If the function succeeds, the return value is a handle to the compatible bitmap.

If the function fails, the return value is **NULL**.

## Remarks

The DDB that is created will be whatever bit depth your reference DC is. To create a bitmap that is of different bit depth, use [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection).

For a device to reach optimal bitmap-drawing speed, specify *fdwInit* as CBM_INIT. Then, use the same color depth DIB as the video mode. When the video is running 4- or 8-bpp, use DIB_PAL_COLORS.

The CBM_CREATDIB flag for the *fdwInit* parameter is no longer supported.

When you no longer need the bitmap, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color management is performed. The contents of the resulting bitmap are not color matched after the bitmap has been created.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)