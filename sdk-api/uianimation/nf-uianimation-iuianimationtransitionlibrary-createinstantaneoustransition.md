# IUIAnimationTransitionLibrary::CreateInstantaneousTransition

## Description

Creates an instantaneous transition.

## Parameters

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new instantaneous transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During an instantaneous transition,
the value of the animation variable changes instantly from its current value to a specified final value. The duration of this transition is always zero.

The figure below shows the effect on an animation variable over time during an instantaneous transition.

![Diagram showing an instantaneous transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/InstantaneousTransition.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)