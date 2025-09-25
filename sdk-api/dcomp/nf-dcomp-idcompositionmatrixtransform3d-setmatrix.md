# IDCompositionMatrixTransform3D::SetMatrix

## Description

Changes all values of the matrix of this 3D transformation effect.

## Parameters

### `matrix` [ref]

Type: **const [D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix)**

The new matrix for this 3D transformation effect.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if any of the matrix values are NaN, positive infinity, or negative infinity.

If any of the matrix elements were previously animated, this method removes the animations and sets the elements to the specified static value.

## See also

[IDCompositionMatrixTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform3d)