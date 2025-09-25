# IUIAnimationTransitionLibrary::CreateParabolicTransitionFromAcceleration

## Description

Creates a parabolic-acceleration transition.

## Parameters

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `finalVelocity` [in]

The velocity at the end of the transition.

### `acceleration` [in]

The acceleration during the transition.

### `transition` [out]

The new parabolic-acceleration transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a parabolic-acceleration transition, the value of the animation variable changes from the initial value to the final value ending at the specified velocity. You can control how quickly the variable reaches the final value by specifying the rate of acceleration.

The figure below shows the effect on an animation variable over time during a parabolic-acceleration transition.

![Diagram showing a parabolic-acceleration transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/ParabolicTransitionFromAcceleration.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)