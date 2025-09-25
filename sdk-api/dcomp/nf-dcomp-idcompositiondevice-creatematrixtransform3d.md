# IDCompositionDevice::CreateMatrixTransform3D

## Description

Creates a 3D 4-by-4 matrix transform object.

## Parameters

### `matrixTransform3D` [out]

Type: **[IDCompositionMatrixTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform3d)****

The new 3D matrix transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The new 3D matrix transform has the identity matrix as its value. The identity matrix is the 4-by-4 matrix with ones on the main diagonal and zeros elsewhere, as shown in the following illustration.

![Four-by-four identity matrix](https://learn.microsoft.com/windows/win32/api/dcomp/images/identity_4x4matrix.png)

When an identity transform is applied to an object, it does not change the position, shape, or size of the object. It is similar to the way that multiplying a number by one does not change the number. Any transform other than the identity transform will modify the position, shape, and/or size of objects.

## See also

[DCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)