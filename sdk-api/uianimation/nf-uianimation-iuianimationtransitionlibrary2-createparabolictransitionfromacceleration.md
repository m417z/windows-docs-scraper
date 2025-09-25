# IUIAnimationTransitionLibrary2::CreateParabolicTransitionFromAcceleration

## Description

Creates a parabolic-acceleration scalar transition.

## Parameters

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `finalVelocity` [in]

The velocity, in units/second, at the end of the transition.

### `acceleration` [in]

The acceleration, in units/second², during the transition.

### `transition` [out]

The new parabolic-acceleration transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a parabolic-acceleration transition, the value of the animation variable changes from the initial value to the final value, ending at the specified velocity. You can control how quickly the variable reaches the final value by specifying the rate of acceleration.

The following figure shows the change in value over time of an animation variable during a parabolic-acceleration transition.

![Diagram showing a parabolic-acceleration transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/ParabolicTransitionFromAcceleration.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)