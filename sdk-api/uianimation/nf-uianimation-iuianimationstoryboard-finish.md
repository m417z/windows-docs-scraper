# IUIAnimationStoryboard::Finish

## Description

Finishes the storyboard within the specified time, compressing the storyboard if necessary.

## Parameters

### `completionDeadline` [in]

The maximum amount of time that the storyboard can use to finish playing.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method has no effect on storyboard events. Events continue to be raised as expected while the storyboard plays.

## See also

[IUIAnimationManager::FinishAllStoryboards](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-finishallstoryboards)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-abandon)

[IUIAnimationStoryboard::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-conclude)

[IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule)