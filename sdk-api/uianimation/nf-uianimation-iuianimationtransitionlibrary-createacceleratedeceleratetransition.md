# IUIAnimationTransitionLibrary::CreateAccelerateDecelerateTransition

## Description

Creates an accelerate-decelerate transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `accelerationRatio` [in]

The ratio of the time spent accelerating to the duration.

### `decelerationRatio` [in]

The ratio of the time spent decelerating to the duration.

### `transition` [out]

The new accelerate-decelerate transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During an accelerate-decelerate transition, the animation variable
speeds up and then slows down over the duration of the transition, ending at a specified value. You can control how quickly the variable accelerates and decelerates independently, by specifying different acceleration and deceleration ratios.

When the initial velocity is zero, the acceleration ratio is the fraction of the duration that the variable will spend accelerating; likewise with the deceleration ratio. If the initial velocity is nonzero, it is the fraction of the time between the velocity reaching zero and the end of transition. The acceleration ratio and the deceleration ratio should sum to a maximum of 1.0.

The figures below show the effect on animation variables with different initial velocities during accelerate-decelerate transitions.

![Diagram showing accelerate-decelerate transitions](https://learn.microsoft.com/windows/win32/api/uianimation/Images/AccelerateDecelerateTransition.png)

**Note** d' in the above figure on the right shows the time between the velocity reaching zero and the end of the transition.

#### Examples

For an example, see [Create a Storyboard and Add Transitions](https://learn.microsoft.com/windows/desktop/UIAnimation/updating---timer-driven-animation).

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)