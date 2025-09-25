# IDCompositionMatrixTransform::SetMatrix

## Description

Changes all values of the matrix of this 2D transform.

## Parameters

### `matrix` [ref]

Type: **const [D2D_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_matrix_3x2_f)**

The new matrix for this 2D transform.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if any of the matrix values are NaN, positive infinity, or negative infinity.

If any of the matrix elements were previously animated, this method removes the animations and sets the elements to the specified static value.

## See also

[IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform)