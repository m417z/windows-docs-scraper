# IUIAnimationStoryboard2::GetStatus

## Description

Gets the status of the storyboard.

## Parameters

### `status` [out, retval]

The storyboard status.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Unless this method is called from a handler for [OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler2-onstoryboardstatuschanged) events, the only values it returns are [UI_ANIMATION_STORYBOARD_BUILDING](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status), **UI_ANIMATION_STORYBOARD_SCHEDULED**,
**UI_ANIMATION_STORYBOARD_PLAYING**, and **UI_ANIMATION_STORYBOARD_READY**.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboardEventHandler2::OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler2-onstoryboardstatuschanged)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)