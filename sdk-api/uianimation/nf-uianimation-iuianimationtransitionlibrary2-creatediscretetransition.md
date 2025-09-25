# IUIAnimationTransitionLibrary2::CreateDiscreteTransition

## Description

Creates a discrete scalar transition.

## Parameters

### `delay` [in]

The amount of time by which to delay the instantaneous switch to the final value.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `hold` [in]

The amount of time by which to hold the variable at its final value.

### `transition` [out]

The new discrete transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a discrete transition, the animation variable remains at the initial value for a specified delay time, then switches instantaneously to a specified final value and remains at that value for a given hold time.

The following figure shows the change in value over time of an animation variable during a discrete transition.

![Diagram showing a discrete transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/DiscreteTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)