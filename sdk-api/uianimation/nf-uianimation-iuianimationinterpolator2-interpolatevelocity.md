# IUIAnimationInterpolator2::InterpolateVelocity

## Description

Interpolates the velocity, or rate of change, at the specified offset for the given dimension.

## Parameters

### `offset` [in]

The offset from the start of the transition.

The offset is always greater than or equal to zero and less than or equal to the duration of the transition. This method is not called if the duration of the transition is zero.

### `velocity` [out]

The interpolated velocity.

### `cDimension` [in]

The dimension in which to interpolate the velocity.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation always calls the [IUIAnimationInterpolator2::SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) method to set the initial value and velocity before calling **InterpolateVelocity**, so a custom interpolator need not check whether the initial value and velocity have been set.

Windows Animation can call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to **InterpolateVelocity** reflect the updated state.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)

[UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds)