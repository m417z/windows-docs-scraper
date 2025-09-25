# IUIAnimationStoryboardEventHandler::OnStoryboardUpdated

## Description

Handles events that occur when a storyboard is updated.

## Parameters

### `storyboard` [in]

The storyboard that has been updated.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method is called when the value of at least one of the variables that a storyboard is animating has changed since the last call to the [IUIAnimationManager::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-update) method.

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnStoryboardUpdated**:

* [IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)
* [IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)
* [IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)
* [IUIAnimationVariable::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getcurrentstoryboard)
* [IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)
* [IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)
* [IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)
* [IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)
* [IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)
* [IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)
* [IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)

## See also

[IUIAnimationManager::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-update)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::GetElapsedTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getelapsedtime)

[IUIAnimationStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler)