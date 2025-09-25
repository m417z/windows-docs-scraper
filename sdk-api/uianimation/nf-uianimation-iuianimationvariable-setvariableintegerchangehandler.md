# IUIAnimationVariable::SetVariableIntegerChangeHandler

## Description

Specifies an integer variable change handler. This handler is notified of changes to the integer value of the animation variable.

## Parameters

### `handler` [in, optional]

An integer variable change handler.
The specified object must implement the [IUIAnimationVariableIntegerChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariableintegerchangehandler) interface or be NULL.

See Remarks.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing NULL for the *handler* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

[IUIAnimationVariableIntegerChangeHandler::OnIntegerValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariableintegerchangehandler-onintegervaluechanged) is called only if the rounded value has changed since the last update.

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::SetVariableChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setvariablechangehandler)

[IUIAnimationVariableChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariablechangehandler)