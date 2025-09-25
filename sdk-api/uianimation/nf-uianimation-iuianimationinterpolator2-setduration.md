# IUIAnimationInterpolator2::SetDuration

## Description

Sets the duration of the transition in the given dimension.

## Parameters

### `duration` [in, out]

The duration of the transition.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation calls this method only after calling the [IUIAnimationInterpolator2::GetDependencies](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-getdependencies) method, and only if that call returns **UI_ANIMATION_DEPENDENCY_DURATION** as one of its *durationDependencies* flags.

Typically, an interpolator with a duration dependency has a duration parameter in the [IUIAnimationTransitionFactory](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionfactory) or [IUIAnimationTransitionFactory2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionfactory2) creation method that is associated with that interpolator. The interpolator should store its duration when first initialized and overwrite the duration when **SetDuration** is called.

Windows Animation always calls the [IUIAnimationInterpolator2::SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) method to set the initial value and velocity before calling **SetDuration**, so a custom interpolator doesn't need to check whether the initial value and velocity have been set.

Windows Animation can call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) and **SetDuration** multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to **SetDuration** reflect the updated state.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)

[UI_ANIMATION_DEPENDENCIES](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_dependencies)

[UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds)