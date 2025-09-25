# IUIAnimationTransitionLibrary2::CreateSinusoidalTransitionFromVelocity

## Description

Creates a sinusoidal scalar transition where amplitude is determined by initial velocity.

## Parameters

### `duration` [in]

The duration of the transition.

### `period` [in]

The period of oscillation of the sinusoidal wave.

### `transition` [out]

The new sinusoidal-velocity transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The value of the animation variable oscillates around the initial value over the entire duration of a sinusoidal-range transition. The amplitude of the oscillation is determined by the velocity when the transition begins.

The following figure shows the change in value over time of an animation variable during a sinusoidal-velocity transition.

![Diagram showing a sinusoidal-velocity transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SinusolidalTransitionFromVelocity.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)