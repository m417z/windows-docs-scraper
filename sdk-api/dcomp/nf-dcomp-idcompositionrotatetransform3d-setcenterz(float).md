# IDCompositionRotateTransform3D::SetCenterZ

## Description

Changes the value of the CenterZ property of a 3D rotation transform. The CenterZ property specifies the z-coordinate of the point about which the rotation is performed. The default value is zero.

## Parameters

### `centerZ` [in]

Type: **float**

The new z-coordinate of the center point.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *centerZ* parameter is NaN, positive infinity, or negative infinity.

If the CenterZ property was previously animated, this method removes the animation and sets the CenterZ property to the specified static value.

## See also

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionRotateTransform3D::SetCenterX](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setcenterx(float))

[IDCompositionRotateTransform3D::SetCenterY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionrotatetransform3d-setcentery(float))