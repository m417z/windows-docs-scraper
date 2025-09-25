# IDCompositionScaleTransform3D::SetScaleZ

## Description

Changes the value of the ScaleZ property of a 3D scale transform. The ScaleZ property specifies the scale factor along the z-axis.

## Parameters

### `scaleZ` [in]

Type: **float**

The new z-axis scale factor.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *scaleZ* parameter is NaN, positive infinity, or negative infinity.

If the ScaleZ property was previously animated, this method removes the animation and sets the ScaleZ property to the specified static value.

## See also

[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionScaleTransform3D::SetScaleX](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionscaletransform3d-setscalex(float))

[IDCompositionScaleTransform3D::SetScaleY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionscaletransform3d-setscaley(float))