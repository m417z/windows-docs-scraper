# IUIAnimationTransition2::IsDurationKnown

## Description

Determines whether the duration of a transition is known.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method should not be called when the storyboard to which the transition has been added is scheduled or playing.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransition2::GetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-getduration)