# IDCompositionRotateTransform3D::SetAxisX

## Description

Changes the value of the AxisX property of a 3D rotation transform. The AxisX property specifies the x-coordinate for the axis vector of rotation. The default value is zero.

## Parameters

### `axisX` [in]

Type: **float**

The new x-coordinate for the axis vector of rotation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

When setting the axis to a non-default value, you should always set all three axis properties (AxisX, AxisY, and AxisZ).

This method fails if the *axisX* parameter is NaN, positive infinity, or negative infinity.

If the AxisX property was previously animated, this method removes the animation and sets the AxisX property to the specified static value.

## See also

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionRotateTransform3D::SetAxisY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisy(float))

[IDCompositionRotateTransform3D::SetAxisZ](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisz(float))