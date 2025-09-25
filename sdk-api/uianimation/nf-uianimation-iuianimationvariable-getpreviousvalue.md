# IUIAnimationVariable::GetPreviousValue

## Description

Gets the previous value of the animation variable. This is the value of the animation variable before the most recent update.

## Parameters

### `previousValue` [out]

The previous value of the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The results can be affected by the lower and upper bounds determined by [IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound) and [IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound), respectively.

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)

[IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)

[IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound)

[IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound)