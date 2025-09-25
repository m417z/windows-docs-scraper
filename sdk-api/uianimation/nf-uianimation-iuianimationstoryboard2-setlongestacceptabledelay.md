# IUIAnimationStoryboard2::SetLongestAcceptableDelay

## Description

Sets the longest acceptable delay before the scheduled storyboard begins.

## Parameters

### `delay` [in]

The longest acceptable delay. This parameter can be a positive value, or [UI_ANIMATION_SECONDS_EVENTUALLY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds-eventually) (-1) to indicate that any finite delay is acceptable.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

For Windows Animation to schedule a storyboard successfully, the storyboard must begin before the longest acceptable delay has elapsed. Windows Animation determines this delay in the following order: the delay value set by calling this method, the delay value set by calling the [IUIAnimationManager2::SetDefaultLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-setdefaultlongestacceptabledelay) method, or 0.0 if neither of these methods has been called.

 Use [IUIAnimationStoryboard2::SetSkipDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setskipduration) to start a storyboard animation at a specified offset instead of delaying the start of a storyboard.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[SetSkipDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setskipduration)