# IDCompositionMatrixTransform::SetMatrixElement(int,int,IDCompositionAnimation)

## Description

Animates the value of one element of the matrix of this 2D transform.

## Parameters

### `row` [in]

The row index of the element to change. This value must be between 0 and 2, inclusive.

### `column` [in]

The column index of the element to change. This value must be between 0 and 1, inclusive.

### `animation` [in]

An animation that represents how the value of the specified element changes over time. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method makes a copy of the specified animation. If the object referenced by the *animation* parameter is changed after calling this method, the change does not affect the element unless this method is called again. If the element was previously animated, calling this method replaces the previous animation with the new animation.

This method fails if *animation* is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as the affected transform. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

## See also

[IDCompositionMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform)