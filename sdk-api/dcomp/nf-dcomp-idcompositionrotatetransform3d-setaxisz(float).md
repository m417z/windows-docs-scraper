# IDCompositionRotateTransform3D::SetAxisZ

## Description

Changes the value of the AxisZ property of a 3D rotation transform. The AxisZ property specifies the z-coordinate for the axis vector of rotation. The default value is 1.0.

## Parameters

### `axisZ` [in]

Type: **float**

The new z-coordinate for the axis vector of rotation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

When setting the axis to a non-default value, you should always set all three axis properties (AxisX, AxisY, and AxisZ).

This method fails if the *axisZ* parameter is NaN, positive infinity, or negative infinity.

If the AxisZ property was previously animated, this method removes the animation and sets the AxisX property to the specified static value.

## See also

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionRotateTransform3D::SetAxisX](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisx(float))

[IDCompositionRotateTransform3D::SetAxisY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setaxisy(float))