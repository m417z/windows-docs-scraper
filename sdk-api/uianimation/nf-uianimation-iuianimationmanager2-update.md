# IUIAnimationManager2::Update

## Description

Updates the values of all animation variables.

## Parameters

### `timeNow` [in]

The current system time. This parameter must be greater than or equal to 0.0.

### `updateResult` [out, optional]

The result of the update.
You can omit this parameter from calls to this method.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calling this method advances the animation manager to *timeNow*, changes the status of all storyboards as necessary, and updates any animation variables to appropriate interpolated values. If the animation manager is paused, no storyboards or variables are updated. If the animation mode is [UI_ANIMATION_MODE_DISABLED](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode), all scheduled storyboards finish playing immediately. If the values of any variables change during this call, the value of *updateResult* is [UI_ANIMATION_UPDATE_VARIABLES_CHANGED](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_update_result); otherwise, it is [UI_ANIMATION_UPDATE_NO_CHANGE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_update_result).

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[IUIAnimationManager2::Pause](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-pause)

[IUIAnimationManager2::Resume](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-resume)

[IUIAnimationManager::SetAnimationMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-setanimationmode)

[UI_ANIMATION_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode)

[UI_ANIMATION_UPDATE_RESULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_update_result)