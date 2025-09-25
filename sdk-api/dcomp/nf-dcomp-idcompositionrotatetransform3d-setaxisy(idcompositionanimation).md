# IDCompositionRotateTransform3D::SetAxisY(IDCompositionAnimation)

## Description

Animates the value of the AxisY property of a 3D rotation transform. The AxisY property specifies the y-coordinate for the axis vector of rotation. The default value is zero.

## Parameters

### `animation` [in]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)***

An animation object that determines how the value of the AxisY property changes over time. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

When setting the axis to a non-default value, you should always set all three axis properties (AxisX, AxisY, and AxisZ).

This method makes a copy of the specified animation. If the object referenced by the *animation* parameter is changed after calling this method, the change does not affect the AxisY property unless this method is called again. If the AxisY property was previously animated, calling this method replaces the previous animation with the new animation.

This method fails if *animation* is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as the affected 3D transform. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

## See also

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionRotateTransform3D::SetAxisX](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisx(float))

[IDCompositionRotateTransform3D::SetAxisZ](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisz(float))