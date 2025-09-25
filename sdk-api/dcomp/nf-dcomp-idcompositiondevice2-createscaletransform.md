# IDCompositionDevice2::CreateScaleTransform

## Description

Creates a 2D scale transform object.

## Parameters

### `scaleTransform` [out]

Type: **[IDCompositionScaleTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)****

The new 2D scale transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new 2D scale transform object has a static value of zero for the ScaleX, ScaleY, CenterX, and CenterY properties.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))