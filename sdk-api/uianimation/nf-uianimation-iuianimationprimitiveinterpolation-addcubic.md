# IUIAnimationPrimitiveInterpolation::AddCubic

## Description

Adds a cubic polynomial segment that describes the shape of a transition curve to the animation function.

## Parameters

### `dimension` [in]

The dimension in which to apply the new segment.

### `beginOffset` [in]

The begin offset for the segment, where 0 corresponds to the start of the transition.

### `constantCoefficient` [in]

The cubic polynomial constant coefficient.

### `linearCoefficient` [in]

The cubic polynomial linear coefficient.

### `quadraticCoefficient` [in]

The cubic polynomial quadratic coefficient.

### `cubicCoefficient` [in]

The cubic polynomial cubic coefficient.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method will fail with an error code of UI_E_INVALID_PRIMITIVE if the start time is either less than 0
or less than the start time of a previous segment.

## See also

[IUIAnimationPrimitiveInterpolation](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprimitiveinterpolation)