# InvertRgn function

## Description

The **InvertRgn** function inverts the colors in the specified region.

## Parameters

### `hdc` [in]

Handle to the device context.

### `hrgn` [in]

Handle to the region for which colors are inverted. The region's coordinates are presumed to be logical coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

On monochrome screens, the **InvertRgn** function makes white pixels black and black pixels white. On color screens, this inversion is dependent on the type of technology used to generate the colors for the screen.

#### Examples

For an example, see [Using Brushes](https://learn.microsoft.com/windows/desktop/gdi/using-brushes).

## See also

[FillRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillrgn)

[PaintRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-paintrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)