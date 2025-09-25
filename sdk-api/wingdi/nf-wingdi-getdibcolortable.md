# GetDIBColorTable function

## Description

The **GetDIBColorTable** function retrieves RGB (red, green, blue) color values from a range of entries in the color table of the DIB section bitmap that is currently selected into a specified device context.

## Parameters

### `hdc` [in]

A handle to a device context. A DIB section bitmap must be selected into this device context.

### `iStart` [in]

A zero-based color table index that specifies the first color table entry to retrieve.

### `cEntries` [in]

The number of color table entries to retrieve.

### `prgbq` [out]

A pointer to a buffer that receives an array of [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad) data structures containing color information from the DIB color table. The buffer must be large enough to contain as many **RGBQUAD** data structures as the value of *cEntries*.

## Return value

If the function succeeds, the return value is the number of color table entries that the function retrieves.

If the function fails, the return value is zero.

## Remarks

The **GetDIBColorTable** function should be called to retrieve the color table for DIB section bitmaps that use 1, 4, or 8 bpp. The **biBitCount** member of a bitmap associated [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure specifies the number of bits-per-pixel. DIB section bitmaps with a **biBitCount** value greater than eight do not have a color table, but they do have associated color masks. Call the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function to retrieve those color masks.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)

[SetDIBColorTable](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibcolortable)