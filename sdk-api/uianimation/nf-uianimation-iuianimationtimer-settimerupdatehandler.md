# IUIAnimationTimer::SetTimerUpdateHandler

## Description

Specifies a timer update handler.

## Parameters

### `updateHandler` [in, optional]

A timer update handler, or **NULL** (see Remarks). The specified object must implement the
[IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler) interface.

### `idleBehavior` [in]

A member of
[UI_ANIMATION_IDLE_BEHAVIOR](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_idle_behavior)
that specifies the behavior of the timer when it is idle.

## Return value

If the method succeeds, it returns S_OK. If the update handler is already connected to a timer, this method returns **UI_E_TIMER_CLIENT_ALREADY_CONNECTED**. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The timer update handler receives time updates (ticks) from the timer. The timer indicates an update by calling
the [IUIAnimationTimerUpdateHandler::OnUpdate](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimerupdatehandler-onupdate)
method on the specified handler.

Passing **NULL** for the *updateHandler* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

#### Examples

For an example, see [Update the Animation Manager](https://learn.microsoft.com/windows/desktop/UIAnimation/introducing-windows-animation-manager).

## See also

[IUIAnimationTimer](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimer)

[IUIAnimationTimer::SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler)

[IUIAnimationTimerUpdateHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimerupdatehandler)