# DCOMPOSITION_COMPOSITE_MODE enumeration

## Description

The mode to use to blend the bitmap content of a visual with the render target.

## Constants

### `DCOMPOSITION_COMPOSITE_MODE_SOURCE_OVER:0`

The standard source-over-destination blend mode.

### `DCOMPOSITION_COMPOSITE_MODE_DESTINATION_INVERT:1`

The bitmap colors are inverted.

### `DCOMPOSITION_COMPOSITE_MODE_MIN_BLEND:2`

Bitmap colors subtract for color channels in the background.

### `DCOMPOSITION_COMPOSITE_MODE_INHERIT:0xffffffff`

Bitmaps are blended according to the mode established by the parent visual.

## Remarks

A single visual can have any combination of visual properties. However, if a
visual has the following combination of properties, the borders of the visual will default
to [DCOMPOSITION_BORDER_MODE_HARD](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode).

* `SetCompositeMode(DCOMPOSITION_COMPOSITE_MODE_DESTINATION_INVERT)`
* `SetBorderMode(DCOMPOSITION_BORDER_MODE_SOFT)`
* `SetBitmapInterpolationMode(DCOMPOSITION_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR)`

If you want a visual to be drawn with antialiasing, use [DCOMPOSITION_BITMAP_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_bitmap_interpolation_mode) for the content of the visual, and [DCOMPOSITION_BORDER_MODE_SOFT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode) for the edges.

## See also

[IDCompositionVisual::SetCompositeMode](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setcompositemode)