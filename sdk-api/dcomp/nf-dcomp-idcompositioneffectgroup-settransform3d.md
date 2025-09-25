# IDCompositionEffectGroup::SetTransform3D

## Description

Sets the 3D transformation effect object that modifies the rasterization of the visuals that this effect group is applied to.

## Parameters

### `transform3D` [in, optional]

Type: **[IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d)***

Pointer to an [IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d) interface or one of its derived interfaces. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if *transform3D* is an invalid pointer, or if the pointer was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as this effect group. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

If the *transform3D* parameter is NULL, the effect group does not apply any perspective transformations to the visuals. Setting the transform to NULL is equivalent to setting the transform to an [IDCompositionMatrixTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform3d) object where the specified matrix is the identity matrix. However, an application should use a NULL transform whenever possible because it is slightly faster.

## See also

[IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup)

[IDCompositionMatrixTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform3d)

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform3d)

[IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d)

[IDCompositionTranslateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform3d)