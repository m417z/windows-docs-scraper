# IUIAnimationVariable::GetValue

## Description

Gets the current value of the animation variable.

## Parameters

### `value` [out]

The current value of the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The results can be affected by the lower and upper bounds determined by [IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound) and [IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound), respectively.

#### Examples

For an example, see [Read the Animation Variable Values](https://learn.microsoft.com/windows/desktop/UIAnimation/updating---application-driven-animation).

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)

[IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)

[IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)

[IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound)

[IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound)