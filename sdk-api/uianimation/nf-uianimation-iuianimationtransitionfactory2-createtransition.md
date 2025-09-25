# IUIAnimationTransitionFactory2::CreateTransition

## Description

Creates a transition from a custom interpolator for a given dimension.

## Parameters

### `interpolator` [in, optional]

The interpolator from which a transition is to be created.
The specified object must implement the [IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2) interface.

### `transition` [out]

The new transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationInterpolator2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator2)

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionFactory2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionfactory2)