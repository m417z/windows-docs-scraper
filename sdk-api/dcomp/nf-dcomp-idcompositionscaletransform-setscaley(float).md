# IDCompositionScaleTransform::SetScaleY

## Description

Changes the value of the ScaleY property of a 2D scale transform. The ScaleY property specifies the scale factor along the y-axis.

## Parameters

### `scaleY` [in]

Type: **float**

The new y-axis scale factor.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *scaleY* parameter is NaN, positive infinity, or negative infinity.

If the ScaleY property was previously animated, this method removes the animation and sets the ScaleY property to the specified static value.

## See also

[IDCompositionScaleTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform)

[IDCompositionScaleTransform::SetScaleX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449048(v=vs.85))