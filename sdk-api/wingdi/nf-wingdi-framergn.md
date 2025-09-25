# FrameRgn function

## Description

The **FrameRgn** function draws a border around the specified region by using the specified brush.

## Parameters

### `hdc` [in]

Handle to the device context.

### `hrgn` [in]

Handle to the region to be enclosed in a border. The region's coordinates are presumed to be in logical units.

### `hbr` [in]

Handle to the brush to be used to draw the border.

### `w` [in]

Specifies the width, in logical units, of vertical brush strokes.

### `h` [in]

Specifies the height, in logical units, of horizontal brush strokes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[FillRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillrgn)

[PaintRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-paintrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)