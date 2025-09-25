# IUIAnimationTransitionFactory::CreateTransition

## Description

Creates a transition from a custom interpolator.

## Parameters

### `interpolator` [in]

The interpolator from which a transition is to be created.
The specified object must implement the [IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator) interface.

### `transition` [out]

The new transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationInterpolator](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationinterpolator)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionFactory](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionfactory)