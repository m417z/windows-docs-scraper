# IUIAnimationTransitionLibrary::CreateSmoothStopTransition

## Description

Creates a smooth-stop transition.

## Parameters

### `maximumDuration` [in]

The maximum duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `transition` [out]

The new smooth-stop transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A smooth-stop transition slows down as it approaches the specified final value, and reaches it with a velocity of zero. The duration of the transition is determined by the initial velocity, the difference between the initial and final values, and the specified maximum duration. If there is no solution consisting of a single parabolic arc, this method creates a cubic transition.

The figure below shows the effect on an animation variable over time during a smooth-stop transition.

![Diagram showing a smooth stop transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SmoothStopTransition.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)