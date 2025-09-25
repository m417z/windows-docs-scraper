# IUIAnimationTransition::SetInitialVelocity

## Description

Sets the initial velocity for the transition.

## Parameters

### `velocity` [in]

The initial velocity for the transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method should not be called after the transition has been added to a storyboard.