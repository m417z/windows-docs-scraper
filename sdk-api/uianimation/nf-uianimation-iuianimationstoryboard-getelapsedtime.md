# IUIAnimationStoryboard::GetElapsedTime

## Description

Gets the time that has elapsed since the storyboard started playing.

## Parameters

### `elapsedTime` [out]

The elapsed time.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.
See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_STORYBOARD_NOT_PLAYING** | The storyboard is not playing. |

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)