# DCOMPOSITION_BORDER_MODE enumeration

## Description

Specifies the border mode to use when composing a bitmap or applying a clip with any transform such that the edges of the bitmap or clip are not axis-aligned with integer coordinates.

## Constants

### `DCOMPOSITION_BORDER_MODE_SOFT:0`

Bitmap and clip edges are antialiased.

### `DCOMPOSITION_BORDER_MODE_HARD:1`

Bitmap and clip edges are aliased. See Remarks.

### `DCOMPOSITION_BORDER_MODE_INHERIT:0xffffffff`

Bitmap and clip edges are drawn according to the mode established by the parent visual.

## Remarks

The default border mode for any given visual is **DCOMPOSITION_BORDER_MODE_INHERIT**, which delegates the determination of the border mode to the parent visual. If all visuals in a visual tree specify this mode, the default for all visuals is aliased rendering, which is the fastest mode.

A single visual can have any combination of visual properties. However, if a
visual has the following combination of properties, the borders of the visual will default
to **DCOMPOSITION_BORDER_MODE_HARD**.

* `SetCompositeMode(DCOMPOSITION_COMPOSITE_MODE_DESTINATION_INVERT)`
* `SetBorderMode(DCOMPOSITION_BORDER_MODE_SOFT)`
* `SetBitmapInterpolationMode(DCOMPOSITION_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR)`

If you want a visual to be drawn with antialiasing, use [DCOMPOSITION_BITMAP_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_bitmap_interpolation_mode) for the content of the visual, and **DCOMPOSITION_BORDER_MODE_SOFT** for the edges.

## See also

[IDCompositionVisual::SetBorderMode](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setbordermode)