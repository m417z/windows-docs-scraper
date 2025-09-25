# IUIAnimationTransition2::SetInitialVectorValue

## Description

Sets the initial value of the transition for each specified dimension in the animation variable.

## Parameters

### `value` [in]

A vector (of size *cDimension*) that contains the initial values for the transition.

### `cDimension` [in]

The number of dimensions that require transition values. This parameter specifies the number of values listed in *value*.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The animation manager should not call this method after the transition has been added to a storyboard.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)