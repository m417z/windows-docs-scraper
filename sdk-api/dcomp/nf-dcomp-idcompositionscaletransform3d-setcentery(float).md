# IDCompositionScaleTransform3D::SetCenterY

## Description

Changes the value of the CenterY property of a 3D scale transform. The CenterY property specifies the y-coordinate of the point about which scaling is performed.

## Parameters

### `centerY` [in]

Type: **float**

The new y-coordinate of the center point.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *centerY* parameter is NaN, positive infinity, or negative infinity.

If the CenterY property was previously animated, this method removes the animation and sets the CenterY property to the specified static value.

## See also

[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionScaleTransform3D::SetCenterX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448998(v=vs.85))

[IDCompositionScaleTransform3D::SetCenterZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449012(v=vs.85))