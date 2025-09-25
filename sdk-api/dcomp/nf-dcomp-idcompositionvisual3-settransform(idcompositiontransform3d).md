# IDCompositionVisual3::SetTransform(IDCompositionTransform3D)

## Description

Sets the Transform property of this visual to the specified 3D transform object.

## Parameters

### `transform` [in, optional]

Type: **[IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d)***

The transform object that is used to modify the coordinate system of this visual. This parameter can point to
an [IDCompositionTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform) interface or one of its derived interfaces. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Setting the Transform property transforms the coordinate system of the entire visual subtree that is rooted at this visual. If the Clip property of this visual is specified, the clip rectangle is also transformed.

If the Transform property previously specified a transform matrix, the newly specified transform object replaces the transform matrix.

A transformation specified by the Transform property is applied after the OffsetX and OffsetY properties. In other words, the effect of setting the Transform property and the OffsetX and OffsetY properties is the same as setting only the Transform property on a transform group where the first member of the group is an [IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform) object that has those same OffsetX and OffsetY values. However, you should use the [IDCompositionVisual::SetOffsetX](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setoffsetx(float)) and [SetOffsetY](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setoffsety(idcompositionanimation)) methods whenever possible because they are slightly faster.

This method fails if *transform* is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface that created this visual. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

If the *transform* parameter is NULL, the coordinate system of this visual is transformed only by its OffsetX and OffsetY properties. Setting the Transform property to NULL is equivalent to setting it to an [IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform) object where the specified matrix is the identity matrix. However, an application should set the Transform property to NULL whenever possible because it is slightly faster.

If the OffsetX and OffsetY properties are set to 0, and the Transform property is set to NULL, the coordinate system of the visual is the same as that of its parent.

## See also

[IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform)

[IDCompositionRotateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform)

[IDCompositionScaleTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionSkewTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionskewtransform)

[IDCompositionTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform)

[IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual3](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual3)

[IDCompositionVisual::SetOffsetX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449165(v=vs.85))

[IDCompositionVisual::SetOffsetY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449171(v=vs.85))