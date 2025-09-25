# IUIAnimationTimerEventHandler::OnPostUpdate

## Description

Handles events that occur after an animation update is finished.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [UIAnimation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The [UIAnimationTimer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317021(v=vs.85)) object calls this method only when calls to [IUIAnimationTimerUpdateHandler::OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate) return a result of **UI_ANIMATION_UPDATE_VARIABLES_CHANGED**.

For each tick, a timer calls the following sequence of methods:

* [IUIAnimationTimerEventHandler::OnPreUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpreupdate)
* [IUIAnimationTimerUpdateHandler::OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate)
* **IUIAnimationTimerEventHandler::OnPostUpdate**

[OnPreUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpreupdate) and **OnPostUpdate** are called on the [IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler) registered with [IUIAnimationTimer::SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler). [OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate) is called on the [IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler) registered with [IUIAnimationTimer::SetTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimerupdatehandler).

## See also

[IUIAnimationTimer::SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler)

[IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler)