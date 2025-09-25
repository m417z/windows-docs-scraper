# IDCompositionTranslateTransform::SetOffsetY

## Description

Changes the value of the OffsetY property of a 2D translation transform. The OffsetY property specifies the distance to translate along the y-axis.

## Parameters

### `offsetY` [in]

Type: **float**

The distance to translate along the y-axis, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *offsetY* parameter is NaN, positive infinity, or negative infinity.

If the OffsetY property was previously animated, this method removes the animation and sets the OffsetY property to the specified static value.

## See also

[IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform)

[IDCompositionTranslateTransform::SetOffsetX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449126(v=vs.85))