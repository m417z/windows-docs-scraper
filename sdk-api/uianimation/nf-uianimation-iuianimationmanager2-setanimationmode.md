# IUIAnimationManager2::SetAnimationMode

## Description

Sets the animation mode.

## Parameters

### `mode` [in]

The animation mode.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Use this method to enable or disable animation globally. While animation is disabled, all storyboards finish immediately when they are scheduled. The default mode is [UI_ANIMATION_MODE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode), which lets Windows decide when to enable or disable animation in the application.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[UI_ANIMATION_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode)