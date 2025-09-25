# IUIAnimationInterpolator::SetInitialValueAndVelocity

## Description

Sets the initial value and velocity at the start of the transition.

## Parameters

### `initialValue` [in]

The initial value.

### `initialVelocity` [in]

The initial velocity.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation always calls **SetInitialValueAndVelocity** before calling the other methods of [IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator) at different offsets. However, it can be called multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to these methods reflect the updated state.

## See also

[IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator)