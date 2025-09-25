# IUIAnimationTimerEventHandler::OnPreUpdate

## Description

Handles events that occur before an animation update begins.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [UIAnimation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

For each tick, a timer calls the following sequence of methods:

* **IUIAnimationTimerEventHandler::OnPreUpdate**
* [IUIAnimationTimerUpdateHandler::OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate)
* [IUIAnimationTimerEventHandler::OnPostUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpostupdate)

**OnPreUpdate** and [OnPostUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onpostupdate) are called on the [IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler) registered with the [IUIAnimationTimer::SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler) method. [OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate) is called on the [IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler) registered with the [IUIAnimationTimer::SetTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimerupdatehandler) method.

## See also

[IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler)

[SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler)