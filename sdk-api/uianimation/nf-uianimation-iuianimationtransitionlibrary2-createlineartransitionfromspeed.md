# IUIAnimationTransitionLibrary2::CreateLinearTransitionFromSpeed

## Description

Creates a linear-speed scalar transition.

## Parameters

### `speed` [in]

The absolute value of the velocity in units/second.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new linear-speed transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a linear-speed transition, the value of the animation variable changes at a specified rate. The duration of the transition is determined by the difference between the initial value and the specified final value.

The following figure shows the change in value over time of an animation variable during a linear-speed transition.

![Diagram showing the linear transition from speed](https://learn.microsoft.com/windows/win32/api/uianimation/Images/LinearTransitionFromSpeed.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)