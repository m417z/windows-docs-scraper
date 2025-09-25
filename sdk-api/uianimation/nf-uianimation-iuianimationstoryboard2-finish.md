# IUIAnimationStoryboard2::Finish

## Description

Finishes the storyboard within the specified time, compressing the storyboard if necessary.

## Parameters

### `completionDeadline`

The maximum amount of time that the storyboard can use to finish playing.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method has no effect on storyboard events. Events continue to be raised as expected while the storyboard plays.

## See also

[IUIAnimationManager2::FinishAllStoryboards](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-finishallstoryboards)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-abandon)

[IUIAnimationStoryboard2::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-conclude)

[IUIAnimationStoryboard2::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-schedule)