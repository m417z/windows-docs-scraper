# IDCompositionDevice::CreateScaleTransform3D

## Description

Creates a 3D scale transform object.

## Parameters

### `scaleTransform3D` [out]

Type: **[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform3d)****

The new 3D scale transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new 3D scale transform object has a static value of 1.0 for the ScaleX, ScaleY, and ScaleZ properties.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)