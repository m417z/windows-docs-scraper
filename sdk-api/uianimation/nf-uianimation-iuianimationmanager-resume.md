# IUIAnimationManager::Resume

## Description

Resumes all animations.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

When an animation manager is resumed, and at least one animation is currently scheduled or playing, its status is set to **UI_ANIMATION_MANAGER_BUSY**.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManager::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstatus)

[IUIAnimationManager::Pause](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-pause)

[UI_ANIMATION_MANAGER_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_manager_status)