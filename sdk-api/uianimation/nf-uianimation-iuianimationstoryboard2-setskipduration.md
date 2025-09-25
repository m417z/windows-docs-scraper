# IUIAnimationStoryboard2::SetSkipDuration

## Description

Specifies an offset from the beginning of a storyboard at which to start animating.

## Parameters

### `secondsDuration` [in]

The offset, or amount of time, to skip at the beginning of the storyboard.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calls to **SetSkipDuration** fail if the storyboard has been scheduled.

**SetSkipDuration** does not delay the start of a scheduled storyboard. See [IUIAnimationStoryboard2::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setlongestacceptabledelay) for more info on how to set a delay for a scheduled storyboard.

This diagram shows a skip duration, or offset, for a storyboard.

![Illustration of a storyboard offset](https://learn.microsoft.com/windows/win32/api/uianimation/Images/SetSkipDuration.png)

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setlongestacceptabledelay)