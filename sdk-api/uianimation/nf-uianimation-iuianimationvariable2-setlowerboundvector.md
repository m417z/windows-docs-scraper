# IUIAnimationVariable2::SetLowerBoundVector

## Description

Sets the lower bound (floor) value of each specified dimension for the animation variable. The value of each animation variable should not fall below its lower bound.

## Parameters

### `bound` [in]

A vector (of size *cDimension*) that contains the lower bound values of each dimension.

### `cDimension` [in]

The number of dimensions that require lower bound values. This parameter specifies the number of values listed in *bound*.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)