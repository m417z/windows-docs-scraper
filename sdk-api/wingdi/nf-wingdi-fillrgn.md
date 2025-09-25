# FillRgn function

## Description

The **FillRgn** function fills a region by using the specified brush.

## Parameters

### `hdc` [in]

Handle to the device context.

### `hrgn` [in]

Handle to the region to be filled. The region's coordinates are presumed to be in logical units.

### `hbr` [in]

Handle to the brush to be used to fill the region.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[PaintRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-paintrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)