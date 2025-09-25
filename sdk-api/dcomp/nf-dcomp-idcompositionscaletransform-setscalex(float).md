# IDCompositionScaleTransform::SetScaleX(float)

## Description

Changes the value of the ScaleX property of a 2D scale transform. The ScaleX property specifies the scale factor along the x-axis.

## Parameters

### `scaleX` [in]

Type: **float**

The new x-axis scale factor.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *scaleX* parameter is NaN, positive infinity, or negative infinity.

If the ScaleX property was previously animated, this method removes the animation and sets the ScaleX property to the specified static value.

## See also

[IDCompositionScaleTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionScaleTransform::SetScaleY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449055(v=vs.85))