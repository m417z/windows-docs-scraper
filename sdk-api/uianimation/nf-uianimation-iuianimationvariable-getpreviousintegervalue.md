# IUIAnimationVariable::GetPreviousIntegerValue

## Description

Gets the previous value of the animation variable as an integer.
This is the value of the animation variable before the most recent update.

## Parameters

### `previousValue` [out]

The previous value of the animation variable, converted to an **INT32** value.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

To specify the rounding mode to be used when converting the value, use the [IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode) method.

The result can also be affected by the lower and upper bounds determined by [IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound) and [IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound), respectively.

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)

[IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)

[IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)

[IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound)

[IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode)

[IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound)