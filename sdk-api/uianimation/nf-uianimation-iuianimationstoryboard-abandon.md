# IUIAnimationStoryboard::Abandon

## Description

Terminates the storyboard, releases all related animation variables, and removes the storyboard from the schedule.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method can be called before or after the storyboard starts playing.

This method does not trigger any storyboard events.

## See also

[IUIAnimationManager::AbandonAllStoryboards](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-abandonallstoryboards)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-conclude)

[IUIAnimationStoryboard::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-finish)

[IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule)