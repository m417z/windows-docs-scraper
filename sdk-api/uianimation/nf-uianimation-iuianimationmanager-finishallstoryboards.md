# IUIAnimationManager::FinishAllStoryboards

## Description

Finishes all active storyboards within the specified time interval.

## Parameters

### `completionDeadline` [in]

The maximum time interval during which all storyboards must be finished.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calling **FinishAllStoryboards** ensures that all active storyboards finish within the specified completion deadline. If a storyboard is scheduled to play past the deadline, it is compressed.
A storyboard is considered active if its status is **UI_ANIMATION_STORYBOARD_PLAYING** or **UI_ANIMATION_STORYBOARD_SCHEDULED**.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationStoryboard::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-finish)

[IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)