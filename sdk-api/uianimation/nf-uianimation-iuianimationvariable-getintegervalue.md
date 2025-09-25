# IUIAnimationVariable::GetIntegerValue

## Description

Gets the current value of the animation variable as an integer.

## Parameters

### `value` [out]

The current value of the animation variable, converted to an **INT32** value.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

To specify the rounding mode to be used when converting the value, use the [IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode) method.

The result can also be affected by the lower and upper bounds determined by [IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound) and [IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound), respectively.

#### Examples

For an example, see [Read the Animation Variable Values](https://learn.microsoft.com/windows/desktop/UIAnimation/updating---application-driven-animation).

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)

[IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)

[IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)

[IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound)

[IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode)

[IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound)