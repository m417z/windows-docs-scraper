# IDCompositionSkewTransform::SetCenterX

## Description

Changes the value of the CenterX property of a 2D skew transform. The CenterX property specifies the x-coordinate of the point about which the skew is performed.

## Parameters

### `centerX` [in]

Type: **float**

The new x-coordinate of the center point.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *centerX* parameter is NaN, positive infinity, or negative infinity.

If the CenterX property was previously animated, this method removes the animation and sets the CenterX property to the specified static value.

## See also

[IDCompositionSkewTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionskewtransform)

[IDCompositionSkewTransform::SetCenterY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449081(v=vs.85))