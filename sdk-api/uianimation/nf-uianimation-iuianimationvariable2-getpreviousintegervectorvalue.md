# IUIAnimationVariable2::GetPreviousIntegerVectorValue

## Description

Gets the previous integer value of the animation variable for the specified dimension. This is the value of the animation variable before the most recent update.

## Parameters

### `previousValue` [out]

The previous value of the animation variable as an integer.

### `cDimension` [in]

The dimension from which to get the value of the animation variable.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)