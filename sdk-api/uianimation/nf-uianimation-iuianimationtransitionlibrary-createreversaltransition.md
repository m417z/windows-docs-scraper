# IUIAnimationTransitionLibrary::CreateReversalTransition

## Description

Creates a reversal transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `transition` [out]

The new reversal transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A reversal transition smoothly changes direction over the specified duration. The final value will be the same as the initial value and the final velocity will be the negative of the initial velocity. The figure below shows such a reversal transition.

![Diagram showing a reversal transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/ReversalTransition.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)