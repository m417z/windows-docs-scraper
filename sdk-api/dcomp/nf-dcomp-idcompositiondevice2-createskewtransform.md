# IDCompositionDevice2::CreateSkewTransform

## Description

Creates a 2D skew transform object.

## Parameters

### `skewTransform` [out]

Type: **[IDCompositionSkewTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionskewtransform)****

The new 2D skew transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new 2D skew transform object has a static value of zero for the AngleX, AngleY, CenterX, and CenterY properties.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))