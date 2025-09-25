# IUIAnimationInterpolator::SetDuration

## Description

Sets the duration of the transition.

## Parameters

### `duration` [in]

The duration of the transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Windows Animation calls this method only after calling the [GetDependencies](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-getdependencies) method, and only if that call returns **UI_ANIMATION_DEPENDENCY_DURATION** as one of its *durationDependencies* flags.

Typically, an interpolator with a duration dependency will have a duration parameter in its associated creation method of [IUIAnimationTransitionFactory](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionfactory). The interpolator should store its duration when first initialized and overwrite it when **SetDuration** is called.

Windows Animation always calls the [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-setinitialvalueandvelocity) method to set the initial value and velocity before calling **SetDuration**, so a custom interpolator need not check whether the initial value and velocity have been set.

Windows Animation can call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-setinitialvalueandvelocity) and **SetDuration** multiple times with different parameters. Interpolators can cache internal state to improve performance, but they must update this cached state each time **SetInitialValueAndVelocity** is called and ensure that the results of subsequent calls to **SetDuration** reflect the updated state.

## See also

[IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator)

[UI_ANIMATION_DEPENDENCIES](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_dependencies)

[UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds)