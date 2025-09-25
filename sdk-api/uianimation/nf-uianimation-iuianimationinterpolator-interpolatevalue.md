# IUIAnimationInterpolator::InterpolateValue

## Description

Interpolates the value of an animation variable at the specified offset.

## Parameters

### `offset` [in]

 The offset from the start of the transition.

This parameter is always greater than or equal to zero and less than the duration of the transition. This method is not called if the duration of the transition is zero.

### `value` [out]

The interpolated value.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation always calls the [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-setinitialvalueandvelocity) method to set the initial value and velocity before calling **InterpolateValue**, so a custom interpolator need not check whether the initial value and velocity have been set.

Windows Animation can call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-setinitialvalueandvelocity) multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to **InterpolateValue** reflect the updated state.

## See also

[IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator)

[UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds)