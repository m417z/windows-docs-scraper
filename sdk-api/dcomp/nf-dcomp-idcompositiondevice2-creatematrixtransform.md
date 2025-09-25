# IDCompositionDevice2::CreateMatrixTransform

## Description

Creates a 2D 3-by-2 matrix transform object.

## Parameters

### `matrixTransform` [out]

Type: **[IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform)****

The new matrix transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new matrix transform object has the identity matrix as its initial value. The identity matrix is the 3x2 matrix with ones on the main diagonal and zeros elsewhere, as shown in the following illustration.

![Three-by-two identity matrix](https://learn.microsoft.com/windows/win32/api/dcomp/images/identity_3x2matrix.png)

When an identity transform is applied to an object, it does not change the position, shape, or size of the object. It is similar to the way that multiplying a number by one does not change the number. Any transform other than the identity transform will modify the position, shape, and/or size of objects.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))