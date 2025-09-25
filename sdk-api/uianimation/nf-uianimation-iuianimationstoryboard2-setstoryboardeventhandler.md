# IUIAnimationStoryboard2::SetStoryboardEventHandler

## Description

Specifies a handler for storyboard events.

## Parameters

### `handler` [in, optional]

The handler that Windows Animation should call whenever storyboard status and update events occur.
The specified object must implement the [IUIAnimationStoryboardEventHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler2) interface or be **NULL**. See Remarks for more info.

### `fRegisterStatusChangeForNextAnimationEvent` [in]

If **TRUE**, registers the [OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler2-onstoryboardstatuschanged) event and includes those events in [IUIAnimationManager2::EstimateNextEventTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-estimatenexteventtime), which estimates the time interval until the next animation event. No default value.

### `fRegisterUpdateForNextAnimationEvent` [in]

If **TRUE**, registers the [OnStoryboardUpdated](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler2-onstoryboardupdated) event and includes those events in [IUIAnimationManager2::EstimateNextEventTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-estimatenexteventtime), which estimates the time interval until the next animation event. No default value.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing **NULL** for the *handler* parameter causes Windows Animation to release its reference to any handler object that you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager2::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-shutdown) method.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboardEventHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler2)