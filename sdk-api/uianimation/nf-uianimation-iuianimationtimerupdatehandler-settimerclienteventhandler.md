# IUIAnimationTimerUpdateHandler::SetTimerClientEventHandler

## Description

Specifies a handler for timer client status change events.

## Parameters

### `handler` [in]

A handler for timer client events. The specified object must implement
[IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerclienteventhandler).

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

If the update handler is already connected to the timer, this method returns **UI_E_TIMER_CLIENT_ALREADY_CONNECTED.**

## See also

[IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler)

[IUIAnimationTimerUpdateHandler::ClearTimerClientEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-cleartimerclienteventhandler)