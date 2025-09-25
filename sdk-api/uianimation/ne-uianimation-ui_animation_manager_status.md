# UI_ANIMATION_MANAGER_STATUS enumeration

## Description

Defines the activity status of an animation manager.

## Constants

### `UI_ANIMATION_MANAGER_IDLE:0`

The animation manager is idle; no animations are currently playing.

### `UI_ANIMATION_MANAGER_BUSY:1`

The animation manager is busy; at least one animation is currently playing or scheduled.

## See also

[IUIAnimationManager::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstatus)

[IUIAnimationManagerEventHandler::OnManagerStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanagereventhandler-onmanagerstatuschanged)