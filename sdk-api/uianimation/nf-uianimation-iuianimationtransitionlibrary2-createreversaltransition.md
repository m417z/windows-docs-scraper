# IUIAnimationTransitionLibrary2::CreateReversalTransition

## Description

Creates a reversal scalar transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `transition` [out]

The new reversal transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A reversal transition smoothly changes direction over the specified duration. The final value will be the same as the initial value and the final velocity will be the negative of the initial velocity. The following figure shows such a reversal transition.

![Diagram showing a reversal transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/ReversalTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)