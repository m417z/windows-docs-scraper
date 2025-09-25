# IUIAnimationTransitionLibrary2::CreateLinearTransition

## Description

Creates a linear scalar transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new linear transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a linear transition, the value of the animation variable transitions linearly from its initial value to a specified final value.

The following figure shows the change in value over time of an animation variable during a linear transition.

![Diagram showing a linear transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/LinearTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)