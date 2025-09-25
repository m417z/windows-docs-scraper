# IUIAnimationTransitionLibrary::CreateConstantTransition

## Description

Creates a constant transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `transition` [out]

The new constant transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a constant transition, the value of an animation variable remains at the initial value over the duration of the transition.

The figure below shows the effect on an animation variable over time during a constant-duration transition.

![Diagram showing a constant-duration transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/ConstantTransition.png)

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)