# PaintRgn function

## Description

The **PaintRgn** function paints the specified region by using the brush currently selected into the device context.

## Parameters

### `hdc` [in]

Handle to the device context.

### `hrgn` [in]

Handle to the region to be filled. The region's coordinates are presumed to be logical coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[FillRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)