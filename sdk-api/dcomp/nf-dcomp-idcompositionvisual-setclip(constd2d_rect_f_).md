# IDCompositionVisual::SetClip

## Description

Sets the Clip property of this visual to the specified rectangle. The Clip property restricts the rendering of the
visual subtree that is rooted at this visual to the specified rectangular region.

## Parameters

### `rect` [in, ref]

Type: **const [D2D_RECT_F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_rect_f)**

The rectangle to use to clip this visual. All properties of the rect parameter have a numerical limit of -2^21 to 2^21.
The API accepts numbers outside of this range, but they are always clamped to this range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Setting the Clip property clips this visual along with all visuals in the subtree that is rooted at this visual. The clip is transformed by the OffsetX, OffsetY, and Transform properties.

If the Clip property previously specified a clip object, the newly specified clip rectangle replaces the clip object.

This method fails if any members of the *rect* structure are NaN, positive infinity, or negative infinity.

If the clip rectangle is empty, the visual is fully clipped; that is, the visual is included in the visual tree, but it does not render anything.
To exclude a particular visual from a composition, remove the visual from the visual tree instead of setting an empty clip rectangle.
Removing the visual results in better performance.

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/directcomp/clipping)

[IDCompositionRectangleClip](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrectangleclip)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)