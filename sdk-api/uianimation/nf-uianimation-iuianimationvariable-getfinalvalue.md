# IUIAnimationVariable::GetFinalValue

## Description

Gets the final value of the animation variable.
This is the value after all currently scheduled animations have completed.

## Parameters

### `finalValue` [out]

The final value of the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_VALUE_NOT_DETERMINED** | The final value of the animation variable cannot be determined at this time. |

## Remarks

The result can be affected by the lower and upper bounds determined by [IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound) and [IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound), respectively.

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)

[IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)

[IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)

[IUIAnimationVariable::SetLowerBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setlowerbound)

[IUIAnimationVariable::SetUpperBound](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setupperbound)