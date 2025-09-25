# IUIAnimationTransitionLibrary::CreateSinusoidalTransitionFromVelocity

## Description

Creates a sinusoidal-velocity transition, with an amplitude determined by the initial velocity.

## Parameters

### `duration` [in]

The duration of the transition.

### `period` [in]

The period of oscillation of the sinusoidal wave in seconds.

### `transition` [out]

The new sinusoidal-velocity transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The value of the animation variable oscillates around the initial value over the entire duration of a sinusoidal-range transition. The amplitude of the oscillation is determined by the velocity when the transition begins.

The figure below shows the effect on an animation variable over time during a sinusoidal-velocity transition.

![Diagram showing a sinusoidal-velocity transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SinusolidalTransitionFromVelocity.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)