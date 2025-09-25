# IUIAnimationStoryboard::SetLongestAcceptableDelay

## Description

Sets the longest acceptable delay before the scheduled storyboard begins.

## Parameters

### `delay` [in]

The longest acceptable delay. This parameter can be a positive value, or **UI_ANIMATION_SECONDS_EVENTUALLY** (-1) to indicate that any finite delay is acceptable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

For a storyboard to be successfully scheduled, it must begin before the longest acceptable delay has elapsed. This delay is determined in the following order: the delay value set by calling this method, the delay value set by calling the [IUIAnimationManager::SetDefaultLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setdefaultlongestacceptabledelay) method, or 0.0 if neither of these methods has been called.

## See also

[IUIAnimationManager::SetDefaultLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setdefaultlongestacceptabledelay)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)