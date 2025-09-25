# IDCompositionRotateTransform::SetAngle(float)

## Description

Changes the value of the Angle property of a 2D rotation transform. The Angle property specifies the rotation angle.

## Parameters

### `angle` [in]

Type: **float**

The new rotation angle, in degrees. A positive angle creates a clockwise rotation, and a negative angle creates a counterclockwise rotation. For values less than –360 or greater than 360, the values wrap around and are treated as if the mathematical operation mod(360) was applied.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *angle* parameter is NaN, positive infinity, or negative infinity.

If the Angle property was previously animated, this method removes the animation and sets the Angle property to the specified static value.

## See also

[IDCompositionRotateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform)