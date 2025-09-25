# IDCompositionVisual::SetOffsetX(float)

## Description

Changes the value of the OffsetX property of this visual. The OffsetX property specifies the new offset of the visual along the x-axis, relative to the parent visual.

## Parameters

### `offsetX` [in]

Type: **float**

The new offset of the visual along the x-axis, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *offsetX* parameter is NaN, positive infinity, or negative infinity.

Changing the OffsetX property of a visual transforms the coordinate system of the entire visual subtree that is rooted at that visual. If the Clip property of this visual is specified, the clip rectangle is also transformed.

A transformation that is specified by the Transform property is applied after the OffsetX property. In other words, the effect of setting the Transform property and the OffsetX property is the same as setting only the Transform property on a transform group object where the first member of the group is an [IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform) object that has the same OffsetX value as *offsetX*. However, you should use **IDCompositionVisual::SetOffsetX** whenever possible because it is slightly faster.

If the OffsetX and OffsetY properties are set to 0, and the Transform property is set to NULL, the coordinate system of the visual is the same as that of its parent.

If the OffsetX property was previously animated, this method removes the animation and sets the property to the specified static value.

#### Examples

For an example, see [How to Build a Simple Visual Tree](https://learn.microsoft.com/windows/desktop/directcomp/how-to--build-a-visual-tree).

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual::SetOffsetY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449171(v=vs.85))

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))