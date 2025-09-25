# IUIAnimationManager::SetAnimationMode

## Description

Sets the animation mode.

## Parameters

### `mode` [in]

The animation mode.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method is used to enable or disable animation globally. While animation is disabled, all storyboards finish immediately when they are scheduled. The default mode is **UI_ANIMATION_MODE_SYSTEM_DEFAULT**, which lets Windows decide when to enable or disable animation in the application.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[UI_ANIMATION_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode)