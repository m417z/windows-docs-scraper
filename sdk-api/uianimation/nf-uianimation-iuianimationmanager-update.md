# IUIAnimationManager::Update

## Description

Updates the values of all animation variables.

## Parameters

### `timeNow` [in]

The current system time. This parameter must be greater than or equal to 0.0.

### `updateResult` [out, optional]

The result of the update.
This parameter can be omitted from calls to this method.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calling this method advances the animation manager to *timeNow*, changing statuses of storyboards as necessary and updating any animation variables to appropriate interpolated values. If the animation manager is paused, no storyboards or variables are updated. If the animation mode is **UI_ANIMATION_MODE_DISABLED**, all scheduled storyboards finish playing immediately. If the values of any variables change during this call, the value of *updateResult* is **UI_ANIMATION_UPDATE_VARIABLES_CHANGED**; otherwise, it is **UI_ANIMATION_UPDATE_NO_CHANGE**.

#### Examples

The following example updates the animation manager with the current time. For additional examples, see [Update the Animation Manager and Draw Frames](https://learn.microsoft.com/windows/desktop/UIAnimation/introducing-windows-animation-manager).

```cpp
// Update the animation manager with the current time
UI_ANIMATION_SECONDS secondsNow;
hr = m_pAnimationTimer->GetTime(
    &secondsNow
    );
if (SUCCEEDED(hr))
{
    UI_ANIMATION_UPDATE_RESULT updateResult;
    hr = m_pAnimationManager->Update(
        secondsNow,
        &updateResult
        );
    if (SUCCEEDED(hr))
    {
        if (updateResult == UI_ANIMATION_UPDATE_VARIABLES_CHANGED)
        {
            ...
        }
    }
}
```

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManager::Pause](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-pause)

[IUIAnimationManager::Resume](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-resume)

[IUIAnimationManager::SetAnimationMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setanimationmode)

[UI_ANIMATION_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_mode)

[UI_ANIMATION_UPDATE_RESULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_update_result)