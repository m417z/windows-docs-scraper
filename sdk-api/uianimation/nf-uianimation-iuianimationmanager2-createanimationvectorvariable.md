# IUIAnimationManager2::CreateAnimationVectorVariable

## Description

Creates a new animation variable for each specified dimension.

## Parameters

### `initialValue` [in]

A vector (of size *cDimension*) of initial values for the animation variable.

### `cDimension` [in]

The number of dimensions that require animated values. This parameter specifies the number of values listed in *initialValue*.

### `variable` [out, retval]

The new animation variable.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The initial value of an animation variable is specified when the variable is created. After an animation variable is created, its value cannot be changed directly; it must be updated through the animation manager.

An animation variable is typically created to represent each visual characteristic that is to be animated. For example, an application might create three animation variables for the X, Y, and Z coordinates of an object that can move freely within a three-dimensional space.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)