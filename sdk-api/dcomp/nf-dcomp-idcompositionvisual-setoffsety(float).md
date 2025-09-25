# IDCompositionVisual::SetOffsetY

## Description

Changes the value of the OffsetY property of this visual. The OffsetY property specifies the new offset of the visual along the y-axis, relative to the parent visual.

## Parameters

### `offsetY` [in]

Type: **float**

The new offset of the visual along the y-axis, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *offsetY* parameter is NaN, positive infinity, or negative infinity.

Changing the OffsetY property transforms the coordinate system of the entire visual subtree that is rooted at this visual. If the Clip property of this visual is specified, the clip rectangle is also transformed.

A transformation that is specified by the Transform property is applied after the OffsetY property. In other words, the effect of setting the Transform property and the OffsetY property is the same as setting only the Transform property on a transform group object where the first member of the group is an [IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform) object that has the same OffsetY value as *offsetY*. However, you should use **IDCompositionVisual::SetOffsetY** whenever possible because it is slightly faster.

If the OffsetX and OffsetY properties are set to 0, and the Transform property is set to NULL, the coordinate system of the visual is the same as that of its parent.

If the OffsetY property was previously animated, this method removes the animation and sets the property to the specified static value.

#### Examples

For an example, see [How to Build a Simple Visual Tree](https://learn.microsoft.com/windows/desktop/directcomp/how-to--build-a-visual-tree).

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual::SetOffsetX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449165(v=vs.85))

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))