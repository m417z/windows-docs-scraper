# SetDIBits function

## Description

The **SetDIBits** function sets the pixels in a compatible bitmap (DDB) using the color data found in the specified DIB.

## Parameters

### `hdc` [in]

A handle to a device context.

### `hbm` [in]

A handle to the compatible bitmap (DDB) that is to be altered using the color data from the specified DIB.

### `start` [in]

The starting scan line for the device-independent color data in the array pointed to by the *lpvBits* parameter.

### `cLines` [in]

The number of scan lines found in the array containing device-independent color data.

### `lpBits` [in]

A pointer to the DIB color data, stored as an array of bytes. The format of the bitmap values depends on the **biBitCount** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure pointed to by the *lpbmi* parameter.

### `lpbmi` [in]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that contains information about the DIB.

### `ColorUse` [in]

Indicates whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure was provided and, if so, whether **bmiColors** contains explicit red, green, blue (RGB) values or palette indexes. The *fuColorUse* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | The color table consists of an array of 16-bit indexes into the logical palette of the device context identified by the *hdc* parameter. |
| **DIB_RGB_COLORS** | The color table is provided and contains literal RGB values. |

## Return value

If the function succeeds, the return value is the number of scan lines copied.

If the function fails, the return value is zero.

This can be the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

Optimal bitmap drawing speed is obtained when the bitmap bits are indexes into the system palette.

Applications can retrieve the system palette colors and indexes by calling the [GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries) function. After the colors and indexes are retrieved, the application can create the DIB. For more information, see [System Palette](https://learn.microsoft.com/windows/desktop/gdi/system-palette).

The device context identified by the *hdc* parameter is used only if the DIB_PAL_COLORS constant is set for the *fuColorUse* parameter; otherwise it is ignored.

The bitmap identified by the *hbmp* parameter must not be selected into a device context when the application calls this function.

The scan lines must be aligned on a **DWORD** except for RLE-compressed bitmaps.

The origin for bottom-up DIBs is the lower-left corner of the bitmap; the origin for top-down DIBs is the upper-left corner of the bitmap.

**ICM:** Color management is performed if color management has been enabled with a call to [SetICMMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmmode) with the *iEnableICM* parameter set to ICM_ON. If the bitmap specified by *lpbmi* has a [BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header) that specifies the gamma and endpoints members, or a [BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header) that specifies either the gamma and endpoints members or the profileData and profileSize members, then the call treats the bitmap's pixels as being expressed in the color space described by those members, rather than in the device context's source color space.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries)