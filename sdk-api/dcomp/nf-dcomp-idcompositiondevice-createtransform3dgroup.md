# IDCompositionDevice::CreateTransform3DGroup

## Description

Creates a 3D transform group object that holds an array of 3D transform objects.

## Parameters

### `transforms3D` [in]

Type: **[IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d)****

An array of 3D transform objects that make up this transform group.

### `elements` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the *transforms* array.

### `transform3DGroup` [out]

Type: **[IDCompositionTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform3d)****

The new 3D transform group object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The array entries in a 3D transform group cannot be changed. However, each transform in the array can be modified through its own property setting methods. If a transform in the array is modified, the change is reflected in the computed matrix of the transform group.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)