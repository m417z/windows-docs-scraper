# IUIAnimationTimerClientEventHandler::OnTimerClientStatusChanged

## Description

Handles events that occur when the status of the timer's client changes.

## Parameters

### `newStatus` [in]

The new status of the timer's client.

### `previousStatus` [in]

The previous status of the timer's client.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationTimerClientEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerclienteventhandler)

[IUIAnimationTimerUpdateHandler::ClearTimerClientEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-cleartimerclienteventhandler)

[IUIAnimationTimerUpdateHandler::SetTimerClientEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-settimerclienteventhandler)

[UI_ANIMATION_TIMER_CLIENT_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_timer_client_status)