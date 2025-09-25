# IDCompositionVisual::SetClip(IDCompositionClip)

## Description

Sets the Clip property of this visual to the specified clip object. The Clip property restricts the rendering of the visual subtree
that is rooted at this visual to a rectangular region.

## Parameters

### `clip` [in, optional]

Type: **[IDCompositionClip](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionclip)***

The clip object to associate with this visual. This parameter can be NULL. All float properties of IDCompositionRectangleClip have a numerical limit of -2^21 to 2^21.
The API accepts numbers outside of this range, but they are always clamped to this range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Setting the Clip property clips this visual along with all visuals in the subtree that is rooted at this visual. The clip is transformed by the OffsetX, OffsetY, and Transform properties.

If the Clip property previously specified a clip rectangle, the newly specified Clip object replaces the clip rectangle.

This method fails if *clip* is an invalid pointer or if it was not created by the
same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface that created this visual. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

If *clip* is NULL, the visual is not clipped relative to its parent. However, the visual is clipped by the clip object of the parent visual,
or by the closest ancestor visual that has a clip object. Setting *clip* to NULL is similar to specifying a clip object whose
clip rectangle has the left and top sides set to negative infinity, and the right and bottom sides set to positive infinity. Using a NULL clip object results in slightly better performance.

If *clip* specifies a clip object that has an empty rectangle, the visual is fully clipped; that is, the visual is included in the visual tree,
but it does not render anything. To exclude a particular visual from a composition, remove the visual from the visual tree instead of setting an empty clip rectangle.
Removing the visual results in better performance.

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/directcomp/clipping)

[IDCompositionRectangleClip](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrectangleclip)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)