# IUIAnimationPrimitiveInterpolation::AddSinusoidal

## Description

Adds a sinusoidal segment that describes the shape of a transition curve to the animation function.

## Parameters

### `dimension` [in]

The dimension in which to apply the new segment.

### `beginOffset` [in]

The begin offset for the segment, where 0 corresponds to the start of the transition.

### `bias` [in]

The bias constant in the sinusoidal function.

### `amplitude` [in]

The amplitude constant in the sinusoidal function.

### `frequency` [in]

The frequency constant in the sinusoidal function.

### `phase` [in]

The phase constant in the sinusoidal function.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Defined by the function Y(t) = bias + amplitude*sin(360*frequency*t + phase), where 'sin' is the sin of an angle specified in degrees (for example, sin(n + 360) == sin(n) for any real number 'n').

This method will fail with an error code of UI_E_INVALID_PRIMITIVE if the start time is either less than 0
or less than the start time of a previous segment.

## See also

[IUIAnimationPrimitiveInterpolation](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprimitiveinterpolation)