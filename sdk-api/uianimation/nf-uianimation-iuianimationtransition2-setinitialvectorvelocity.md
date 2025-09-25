# IUIAnimationTransition2::SetInitialVectorVelocity

## Description

Sets the initial velocity of the transition for each specified dimension in the animation variable.

## Parameters

### `velocity` [in]

A vector (of size *cDimension*) that contains the initial velocities for the transition.

### `cDimension` [in]

The number of dimensions that require transition velocities. This parameter specifies the number of values listed in *velocity*.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)