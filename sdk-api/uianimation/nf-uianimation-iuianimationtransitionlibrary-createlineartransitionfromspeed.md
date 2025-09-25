# IUIAnimationTransitionLibrary::CreateLinearTransitionFromSpeed

## Description

Creates a linear-speed transition.

## Parameters

### `speed` [in]

The absolute value of the velocity.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new linear-speed transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a linear-speed transition, the value of the animation variable changes at a specified rate. The duration of the transition is determined by the difference between the initial value and the specified final value.

The figure below shows the effect on an animation variable over time during a linear-speed transition.

![Diagram showing the linear transition from speed](https://learn.microsoft.com/windows/win32/api/uianimation/Images/LinearTransitionFromSpeed.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)