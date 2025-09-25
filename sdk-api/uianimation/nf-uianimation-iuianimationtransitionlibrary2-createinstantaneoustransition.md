# IUIAnimationTransitionLibrary2::CreateInstantaneousTransition

## Description

Creates an instantaneous scalar transition.

## Parameters

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new instantaneous transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During an instantaneous transition,
the value of the animation variable changes instantly from its current value to a specified final value. The duration of this transition is always zero.

The following figure shows the change in value over time of an animation variable during an instantaneous transition.

![Diagram showing an instantaneous transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/InstantaneousTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)