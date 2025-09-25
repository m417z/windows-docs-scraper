# IDCompositionSkewTransform::SetCenterY

## Description

Changes the value of the CenterY property of a 2D skew transform. The CenterY property specifies the y-coordinate of the point about which the skew is performed.

## Parameters

### `centerY` [in]

Type: **float**

The new y-coordinate of the center point.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *centerY* parameter is NaN, positive infinity, or negative infinity.

If the CenterY property was previously animated, this method removes the animation and sets the CenterY property to the specified static value.

## See also

[IDCompositionSkewTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionskewtransform)

[IDCompositionSkewTransform::SetCenterX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449075(v=vs.85))