# IUIAnimationTimerUpdateHandler::OnUpdate

## Description

Handles update events from the timer.

## Parameters

### `timeNow` [in]

The current timer time, in seconds.

### `result` [out]

 Receives a member of the [UI_ANIMATION_UPDATE_RESULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_update_result) enumeration, indicating whether any animation variables changed as a result of the update.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method is used by the [UIAnimationTimer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317021(v=vs.85)) object to update the state of the [UIAnimationManager](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317019(v=vs.85)) object. The **UIAnimationTimer** object calls [UIAnimationTimerEventHandler::OnPostUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpostupdate) only when calls to this method return a result of **UI_ANIMATION_UPDATE_VARIABLES_CHANGED**.

## See also

[IUIAnimationTimerEventHandler::OnPostUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpostupdate)

[IUIAnimationTimerEventHandler::OnPreUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpreupdate)

[IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler)