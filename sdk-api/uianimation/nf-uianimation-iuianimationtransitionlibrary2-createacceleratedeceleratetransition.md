# IUIAnimationTransitionLibrary2::CreateAccelerateDecelerateTransition

## Description

Creates an accelerate-decelerate scalar transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `accelerationRatio` [in]

The ratio of *duration* time spent accelerating (0 to 1).

### `decelerationRatio` [in]

The ratio of *duration* time spent decelerating (0 to 1).

### `transition` [out]

The new accelerate-decelerate transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During an accelerate-decelerate transition, the animation variable
speeds up and then slows down over the duration of the transition, ending at a specified value. You can control how quickly the variable accelerates and decelerates independently, by specifying different acceleration and deceleration ratios.

When the initial velocity is zero, the acceleration ratio is the fraction of the duration that the variable will spend accelerating; likewise for the deceleration ratio. If the value of initial velocity is nonzero, the value is the fraction of the time between the velocity reaching zero and the end of transition. The acceleration ratio and the deceleration ratio should sum to a maximum of 1.0.

The following figures show the change in value for animation variables with different initial velocities during accelerate-decelerate transitions.

![Diagram showing accelerate-decelerate transitions](https://learn.microsoft.com/windows/win32/api/uianimation/Images/AccelerateDecelerateTransition.png)

**Note** d' in the figure on the right shows the time between the velocity reaching zero and the end of the transition.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)