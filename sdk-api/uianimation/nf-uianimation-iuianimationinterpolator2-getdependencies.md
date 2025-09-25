# IUIAnimationInterpolator2::GetDependencies

## Description

For the given dimension, **GetDependencies** retrieves the aspects of the interpolator that depend on the initial value or velocity that is passed to the [IUIAnimationInterpolator2::SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) method or the duration that is passed to the [IUIAnimationInterpolator2::SetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setduration) method.

## Parameters

### `initialValueDependencies` [out]

Aspects of the interpolator that depend on the initial value passed to [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity).

### `initialVelocityDependencies` [out]

Aspects of the interpolator that depend on the initial velocity passed to [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity).

### `durationDependencies` [out]

Aspects of the interpolator that depend on the duration passed to [SetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setduration).

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method is called to identify which aspects of the custom interpolator are affected by certain inputs: value, velocity, and duration. For each of these inputs, the interpolator returns either of the following:

* The bitwise-OR of any members of [UI_ANIMATION_DEPENDENCIES](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_dependencies) that apply.
* **UI_ANIMATION_DEPENDENCY_NONE** if nothing depends on the input.

For example, consider an interpolator that:

* Accepts a final value as a parameter.
* Always comes to a gradual stop at that final value.
* Has a duration determined by the difference between the final value and the initial value.

In this case the interpolator should return **UI_ANIMATION_DEPENDENCY_INTERMEDIATE_VALUES**|**UI_ANIMATION_DURATION** for the *initialValueDependencies* parameter. It should not return **UI_ANIMATION_DEPENDENCY_FINAL_VALUE**, because this value is set when the interpolator is created and is not affected by the initial value. Likewise, the interpolator should not return **UI_ANIMATION_DEPENDENCY_FINAL_VELOCITY**, because the slope of the curve is defined to always be zero when it reaches the final value.

It is important that an interpolator return a correct set of flags. If a flag is not present for an output, Windows Animation assumes that the corresponding parameter does not affect that aspect of the interpolator's results. For example, if the custom interpolator does not include **UI_ANIMATION_DEPENDENCY_FINAL_VALUE** for *initialVelocityDependencies*, Windows Animation may call [SetInitialValueAndVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setinitialvalueandvelocity) with an arbitrary velocity parameter, and then call [GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-getfinalvalue) to determine the final value. The interpolator's implementation of **GetFinalValue** must return the same result no matter which velocity parameter has been passed to **SetInitialValueAndVelocity**, because the interpolator has claimed that the transition's final value does not depend on the initial velocity.

**Note** If the flags returned for *durationDependencies* do not include **UI_ANIMATION_DEPENDENCY_DURATION**, [SetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator2-setduration) will never be called on the interpolator.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)