# IUIAnimationTransitionLibrary2::CreateCubicTransition

## Description

Creates a cubic scalar transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `finalVelocity` [in]

The velocity of the variable at the end of the transition.

### `transition` [out]

The new cubic transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a cubic transition, the value of the animation variable changes from its initial value to the *finalValue* over the *duration* of the transition, ending at the *finalVelocity*.

The following figure shows the effect on an animation variable over time during a cubic transition.

![Diagram showing a cubic transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/CubicTransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)