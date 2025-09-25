# IDCompositionSkewTransform::SetAngleY

## Description

Changes the value of the AngleY property of a 2D skew transform. The AngleY property specifies the skew angle along the y-axis.

## Parameters

### `angleY` [in]

Type: **float**

The new skew angle of the y-axis, in degrees. A positive value creates a counterclockwise skew, and a negative value creates a clockwise skew. For values less than –360 or greater than 360, the values wrap around and are treated as if the mathematical operation mod(360) was applied.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *angleY* parameter is NaN, positive infinity, or negative infinity.

If the AngleY property was previously animated, this method removes the animation and sets the AngleY property to the specified static value.

## See also

[IDCompositionSkewTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionskewtransform)

[IDCompositionSkewTransform::SetAngleX](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionskewtransform-setanglex(float))