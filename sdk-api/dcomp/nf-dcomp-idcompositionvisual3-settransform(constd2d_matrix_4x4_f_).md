# IDCompositionVisual3::SetTransform

## Description

Sets the Transform property of this visual to the specified 4-by-4 transform matrix.

## Parameters

### `matrix` [in, ref]

Type: **const [D2D_MATRIX_4X4_F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_matrix_3x2_f)**

The 4-by-4 transform matrix that is used to modify the coordinate system of this visual.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Setting the Transform property transforms the coordinate system of the entire visual subtree that is rooted at this visual. If the Clip property of this visual is specified, the clip rectangle is also transformed.

If the Transform property previously specified a transform object, the newly specified transform matrix replaces the transform object.

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