# IUIAnimationTransitionLibrary::CreateSinusoidalTransitionFromRange

## Description

Creates a sinusoidal-range transition, with a specified range of oscillation.

## Parameters

### `duration` [in]

The duration of the transition.

### `minimumValue` [in]

The value of the animation variable at a trough of the sinusoidal wave.

### `maximumValue` [in]

The value of the animation variable at a peak of the sinusoidal wave.

### `period` [in]

The period of oscillation of the sinusoidal wave, in seconds.

### `slope` [in]

The slope at the start of the transition.

### `transition` [out]

The new sinusoidal-range transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The value of the animation variable fluctuates between the specified minimum and maximum values over the entire duration of a sinusodial-range transition. The *slope* parameter is used to disambiguate between the two possible sine waves specified by the other parameters.

The figure below shows the effect on an animation variable over time during a sinusoidal-range transition. Passing in the **UI_ANIMATION_SLOPE_INCREASING** enumeration value yields a wave like the solid curve shown in the figure, whereas the **UI_ANIMATION_SLOPE_DECREASING** value yields a wave like the dashed curve.

![Diagram showing a sinusoidal-range transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SinusolidalTransitionFromRange.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)