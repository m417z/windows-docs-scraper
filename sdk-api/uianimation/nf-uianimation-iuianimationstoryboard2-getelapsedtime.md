# IUIAnimationStoryboard2::GetElapsedTime

## Description

Gets the time that has elapsed since the storyboard started playing.

## Parameters

### `elapsedTime` [out]

The elapsed time.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_STORYBOARD_NOT_PLAYING** | The storyboard is not playing. |

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-getstatus)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)