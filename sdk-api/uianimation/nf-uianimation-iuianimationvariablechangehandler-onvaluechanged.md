# IUIAnimationVariableChangeHandler::OnValueChanged

## Description

Handles events that occur when the value of an animation variable changes.

This method receives updates as **DOUBLE** values.
To receive updates as **INT32** values, use the [IUIAnimationVariableIntegerChangeHandler::OnIntegerValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariableintegerchangehandler-onintegervaluechanged) method.

## Parameters

### `storyboard` [in]

The storyboard that is animating the animation variable specified by the *variable* parameter.

### `variable` [in]

The animation variable that has been updated.

### `newValue` [in]

The new value of the animation variable.

### `previousValue` [in]

The previous value of the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnValueChanged**:

* [IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)
* [IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)
* [IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)
* [IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)
* [IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)
* [IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)
* [IUIAnimationVariable::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getcurrentstoryboard)
* [IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)
* [IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)
* [IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)
* [IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)

## See also

[IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)

[IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)

[IUIAnimationVariable::SetVariableChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setvariablechangehandler)

[IUIAnimationVariableChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariablechangehandler)

[IUIAnimationVariableIntegerChangeHandler::OnIntegerValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariableintegerchangehandler-onintegervaluechanged)