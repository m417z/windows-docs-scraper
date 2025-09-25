# IUIAnimationInterpolator2::SetInitialValueAndVelocity

## Description

Sets the initial value and velocity of the transition for the given dimension.

## Parameters

### `initialValue` [in]

The initial value.

### `initialVelocity` [in]

The initial velocity.

### `cDimension` [in]

The dimension in which to set the initial value or velocity of the transition.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation always calls **SetInitialValueAndVelocity** before calling the other methods of [IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2) at different offsets. However, **SetInitialValueAndVelocity** can be called multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to these methods reflect the updated state.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)