# IUIAnimationTransition2::GetDuration

## Description

Gets the duration of the transition.

## Parameters

### `duration` [out]

The duration of the transition, in seconds.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

An application should typically call the [IsDurationKnown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-isdurationknown) method before calling this method.

This method should not be called when the storyboard to which the transition has been added is scheduled or playing.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)