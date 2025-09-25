# IUIAnimationInterpolator2::GetDuration

## Description

Gets the duration of a transition for the given dimension.

## Parameters

### `duration` [out]

The duration of the transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation always calls the [IUIAnimationInterpolator2::SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) method to set the initial value and velocity before calling **GetDuration**, so a custom interpolator need not check whether the initial value and velocity have been set.

Windows Animation can call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to **GetDuration** reflect the updated state.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)