# SetDIBColorTable function

## Description

The **SetDIBColorTable** function sets RGB (red, green, blue) color values in a range of entries in the color table of the DIB that is currently selected into a specified device context.

## Parameters

### `hdc` [in]

A device context. A DIB must be selected into this device context.

### `iStart` [in]

A zero-based color table index that specifies the first color table entry to set.

### `cEntries` [in]

The number of color table entries to set.

### `prgbq` [in]

A pointer to an array of [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad) structures containing new color information for the DIB's color table.

## Return value

If the function succeeds, the return value is the number of color table entries that the function sets.

If the function fails, the return value is zero.

## Remarks

This function should be called to set the color table for DIBs that use 1, 4, or 8 bpp. The **BitCount** member of a bitmap's associated bitmap information header structure.

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure specifies the number of bits-per-pixel. Device-independent bitmaps with a **biBitCount** value greater than 8 do not have a color table.

The **bV5BitCount** member of a bitmap's associated [BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header) structure specifies the number of bits-per-pixel. Device-independent bitmaps with a **bV5BitCount** value greater than 8 do not have a color table.

**ICM:** No color management is performed.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection)

[GetDIBColorTable](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibcolortable)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)