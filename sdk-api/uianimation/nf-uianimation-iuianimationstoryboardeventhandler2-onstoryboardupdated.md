# IUIAnimationStoryboardEventHandler2::OnStoryboardUpdated

## Description

Handles storyboard update events.

## Parameters

### `storyboard` [in]

The storyboard that has been updated.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method is called when the value of at least one of the variables that a storyboard is animating has changed since the last call to the [IUIAnimationManager2::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-update) method.

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnStoryboardUpdated**:

* [IUIAnimationManager2::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstoryboardfromtag)
* [IUIAnimationManager2::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getvariablefromtag)
* [IUIAnimationStoryboard2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-gettag)
* [IUIAnimationVariable2::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getcurrentstoryboard)
* [IUIAnimationVariable2::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalintegervalue)
* [IUIAnimationVariable2::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalvalue)
* [IUIAnimationVariable2::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getintegervalue)
* [IUIAnimationVariable2::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousintegervalue)
* [IUIAnimationVariable2::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousvalue)
* [IUIAnimationVariable2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-gettag)
* [IUIAnimationVariable2::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getvalue)

## See also

[IUIAnimationManager2::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-update)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard2::GetElapsedTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getelapsedtime)

[IUIAnimationStoryboardEventHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler2)