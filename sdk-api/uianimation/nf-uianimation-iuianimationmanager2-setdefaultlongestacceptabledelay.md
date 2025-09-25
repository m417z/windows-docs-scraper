# IUIAnimationManager2::SetDefaultLongestAcceptableDelay

## Description

Sets the default acceptable animation delay. This is the length of time that may pass before storyboards begin.

## Parameters

### `delay` [in]

The default delay. This parameter can be a positive value, or [UI_ANIMATION_SECONDS_EVENTUALLY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds-eventually) (-1) to indicate that any finite delay is acceptable.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

For Windows Animation to schedule a storyboard successfully, the storyboard must begin before the longest acceptable delay has elapsed. Windows Animation determines this delay in the following order: the delay value set by calling [IUIAnimationStoryboard::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-setlongestacceptabledelay) for this specific storyboard, the delay value set by calling this method, or 0.0 if neither method has been called.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[IUIAnimationStoryboard::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-setlongestacceptabledelay)