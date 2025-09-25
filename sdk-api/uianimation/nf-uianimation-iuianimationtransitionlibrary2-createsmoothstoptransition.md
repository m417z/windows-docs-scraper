# IUIAnimationTransitionLibrary2::CreateSmoothStopTransition

## Description

Creates a smooth-stop scalar transition.

## Parameters

### `maximumDuration` [in]

The maximum duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new smooth-stop transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A smooth-stop transition slows down as it approaches the specified final value, and reaches the final value with a velocity of zero. The duration of the transition is determined by the initial velocity, the difference between the initial and final values, and the specified maximum duration. If there is no solution consisting of a single parabolic arc, this method creates a cubic transition.

The following figure shows the change in value over time of an animation variable during a smooth-stop transition.

![Diagram showing a smooth stop transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SmoothStopTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)