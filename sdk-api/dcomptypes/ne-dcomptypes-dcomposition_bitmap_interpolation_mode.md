# DCOMPOSITION_BITMAP_INTERPOLATION_MODE enumeration

## Description

Specifies the interpolation mode to be used when a bitmap is composed with any transform where the pixels in the bitmap don't line up exactly one-to-one with pixels on screen.

## Constants

### `DCOMPOSITION_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR:0`

Bitmaps are interpolated by using nearest-neighbor sampling.

### `DCOMPOSITION_BITMAP_INTERPOLATION_MODE_LINEAR:1`

Bitmaps are interpolated by using linear sampling.

### `DCOMPOSITION_BITMAP_INTERPOLATION_MODE_INHERIT:0xffffffff`

Bitmaps are interpolated according to the mode established by the parent visual.

## Remarks

The default interpolation mode for a visual is **DCOMPOSITION_BITMAP_INTERPOLATION_MODE_INHERIT**. If all visuals in a visual tree specify this mode, the default for all visuals is nearest neighbor sampling, which is the fastest mode.

A single visual can have any combination of visual properties. However, if a
visual has the following combination of properties, the borders of the visual will default
to [DCOMPOSITION_BORDER_MODE_HARD](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode).

* `SetCompositeMode(DCOMPOSITION_COMPOSITE_MODE_DESTINATION_INVERT)`
* `SetBorderMode(DCOMPOSITION_BORDER_MODE_SOFT)`
* `SetBitmapInterpolationMode(DCOMPOSITION_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR)`

If you want a visual to be drawn with antialiasing, use **DCOMPOSITION_BITMAP_INTERPOLATION_MODE_LINEAR** for the content of the visual, and [DCOMPOSITION_BORDER_MODE_SOFT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode) for the edges.

## See also

[IDCompositionVisual::SetBitmapInterpolationMode](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setbitmapinterpolationmode)