# GetDIBits function

## Description

The **GetDIBits** function retrieves the bits of the specified compatible bitmap and copies them into a buffer as a DIB using the specified format.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hbm` [in]

A handle to the bitmap. This must be a compatible bitmap (DDB).

### `start` [in]

The first scan line to retrieve.

### `cLines` [in]

The number of scan lines to retrieve.

### `lpvBits` [out]

A pointer to a buffer to receive the bitmap data. If this parameter is **NULL**, the function passes the dimensions and format of the bitmap to the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure pointed to by the *lpbmi* parameter.

### `lpbmi` [in, out]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that specifies the desired format for the DIB data.

### `usage` [in]

The format of the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure. It must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | The color table should consist of an array of 16-bit indexes into the current logical palette. |
| **DIB_RGB_COLORS** | The color table should consist of literal red, green, blue (RGB) values. |

## Return value

If the *lpvBits* parameter is non-**NULL** and the function succeeds, the return value is the number of scan lines copied from the bitmap.

If the *lpvBits* parameter is **NULL** and **GetDIBits** successfully fills the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, the return value is nonzero.

If the function fails, the return value is zero.

This function can return the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

If the requested format for the DIB matches its internal format, the RGB values for the bitmap are copied. If the requested format doesn't match the internal format, a color table is synthesized. The following table describes the color table synthesized for each format.

| Value | Meaning |
| --- | --- |
| 1_BPP | The color table consists of a black and a white entry. |
| 4_BPP | The color table consists of a mix of colors identical to the standard VGA palette. |
| 8_BPP | The color table consists of a general mix of 256 colors defined by GDI. (Included in these 256 colors are the 20 colors found in the default logical palette.) |
| 24_BPP | No color table is returned. |

If the *lpvBits* parameter is a valid pointer, the first six members of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure must be initialized to specify the size and format of the DIB. The scan lines must be aligned on a **DWORD** except for RLE compressed bitmaps.

A bottom-up DIB is specified by setting the height to a positive number, while a top-down DIB is specified by setting the height to a negative number. The bitmap color table will be appended to the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

If *lpvBits* is **NULL**, **GetDIBits** examines the first member of the first structure pointed to by *lpbi*. This member must specify the size, in bytes, of a [BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader) or a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure. The function uses the specified size to determine how the remaining members should be initialized.

If *lpvBits* is **NULL** and the bit count member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is initialized to zero, **GetDIBits** fills in a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure or [BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader) without the color table. This technique can be used to query bitmap attributes.

The bitmap identified by the *hbmp* parameter must not be selected into a device context when the application calls this function.

The origin for a bottom-up DIB is the lower-left corner of the bitmap; the origin for a top-down DIB is the upper-left corner.

#### Examples

For an example, see [Capturing an Image](https://learn.microsoft.com/windows/desktop/gdi/capturing-an-image).

## See also

[BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader)

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)