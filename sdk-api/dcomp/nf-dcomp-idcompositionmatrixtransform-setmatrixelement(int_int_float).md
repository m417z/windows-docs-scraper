# IDCompositionMatrixTransform::SetMatrixElement(int,int,float)

## Description

Changes the value of one element of the matrix of this transform.

## Parameters

### `row` [in]

Type: **int**

The row index of the element to change. This value must be between 0 and 2, inclusive.

### `column` [in]

Type: **int**

The column index of the element to change. This value must be between 0 and 1, inclusive.

### `value` [in]

Type: **float**

The new value of the specified element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *value* parameter is NaN, positive infinity, or negative infinity.

If the specified element was previously animated, this method removes the animation and sets the element to the specified static value.

## See also

[IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform)