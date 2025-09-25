# IDCompositionDevice::CreateRotateTransform3D

## Description

Creates a 3D rotation transform object.

## Parameters

### `rotateTransform3D` [out]

Type: **[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)****

The new 3D rotation transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new 3D rotation transform object has a default static value of zero for the Angle, CenterX, CenterY, AxisX, and AxisY properties, and a default static value of 1.0 for the AxisZ property.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionEffectGroup::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)