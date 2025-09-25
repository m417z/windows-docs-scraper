# IDCompositionVisual::SetBitmapInterpolationMode

## Description

Sets the BitmapInterpolationMode property, which specifies the mode for Microsoft DirectComposition to use when interpolating pixels from bitmaps that are not axis-aligned or drawn exactly at scale.

## Parameters

### `interpolationMode` [in]

Type: **[DCOMPOSITION_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_bitmap_interpolation_mode)**

The interpolation mode to use.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The interpolation mode affects how a bitmap is composed when it is transformed such that there is no one-to-one correspondence between pixels in the bitmap and pixels on the screen.

By default, a visual inherits the interpolation mode of the parent visual, which may inherit the interpolation mode of its parent visual, and so on. A visual uses the default interpolation mode if this method is never called for the visual, or if this method is called with [DCOMPOSITION_BITMAP_INTERPOLATION_MODE_INHERIT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_bitmap_interpolation_mode). If no visuals set the interpolation mode, the default for the entire visual tree is nearest neighbor interpolation, which offers the lowest visual quality but the highest performance.

If the *interpolationMode* parameter is anything other than [DCOMPOSITION_BITMAP_INTERPOLATION_MODE_INHERIT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_bitmap_interpolation_mode), this visual's bitmap is composed with the specified interpolation mode, and this mode becomes the new default mode for the children of this visual. That is, if the interpolation mode of this visual's children is unchanged or explicitly set to **DCOMPOSITION_BITMAP_INTERPOLATION_MODE_INHERIT**, the bitmaps of the child visuals are composed using the interpolation mode of this visual.

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)