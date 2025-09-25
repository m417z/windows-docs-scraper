# IDCompositionScaleTransform3D::SetScaleX(IDCompositionAnimation)

## Description

Animates the value of the ScaleX property of a scale transform. The ScaleX property specifies the scale factor along the x-axis.

## Parameters

### `animation` [in]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)***

An animation object that determines how the value of the ScaleX property changes over time. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method makes a copy of the specified animation. If the object referenced by the *animation* parameter is changed after calling this method, the change does not affect the ScaleX property unless this method is called again. If the ScaleX property was previously animated, calling this method replaces the previous animation with the new animation.

This method fails if *animation* is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as the affected visual. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

## See also

[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionScaleTransform3D::SetScaleY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionscaletransform3d-setscaley(float))

[IDCompositionScaleTransform3D::SetScaleZ](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionscaletransform3d-setscalez(float))