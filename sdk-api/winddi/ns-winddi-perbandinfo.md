# PERBANDINFO structure

## Description

The PERBANDINFO structure is used as input to a printer graphics DLL's [DrvQueryPerBandInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryperbandinfo) function.

## Members

### `bRepeatThisBand`

If **TRUE**, GDI redraws the previous band. If **FALSE**, GDI draws the next band.

### `szlBand`

Specifies a SIZEL structure that contains the width and height, in pixels, of the rectangle in which GDI can draw the band. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `ulHorzRes`

Specifies the horizontal resolution GDI should use when scaling the band.

### `ulVertRes`

Specifies the vertical resolution GDI should use when scaling the band.

## Remarks

If the result of **ulHorzRes** divided by **ulVertRes** is smaller than the result obtained by dividing the same members of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure, the band is rendered smaller by the graphics engine. If the values are the same, no scaling is done. The resultant scale factor obtained from this structure cannot be larger than the one stored in GDIINFO.

When the band is scaled, the graphics engine anchors the smaller band to the upper-left corner of the original band.

## See also

[DrvQueryPerBandInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryperbandinfo)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)