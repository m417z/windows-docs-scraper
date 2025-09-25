# IUIAnimationTransition2::SetInitialValue

## Description

Sets the initial value of the transition.

## Parameters

### `value` [in]

The initial value for the transition.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Do not call this method after the transition has been added to a storyboard.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)