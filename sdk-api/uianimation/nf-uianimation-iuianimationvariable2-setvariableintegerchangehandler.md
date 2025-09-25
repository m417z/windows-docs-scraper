# IUIAnimationVariable2::SetVariableIntegerChangeHandler

## Description

Specifies a handler for changes to the integer value of the animation variable.

## Parameters

### `handler` [in, optional]

A pointer to the handler for changes to the integer value of the animation variable. This parameter can be **NULL**.

### `fRegisterForNextAnimationEvent` [in]

If **TRUE**, specifies that the [EstimateNextEventTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-estimatenexteventtime) method will incorporate *handler* into its estimate of the time interval until the next animation event. No default value.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing **NULL** for the *handler* parameter causes Windows Animation to release its reference to any handler object that you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-shutdown) method.

[IUIAnimationVariableIntegerChangeHandler2::OnIntegerValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariableintegerchangehandler2-onintegervaluechanged) is called only if the rounded value has changed since the last update.

## See also

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)

[IUIAnimationVariableChangeHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariablechangehandler2)