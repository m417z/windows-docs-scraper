# IUIAnimationStoryboard2::Abandon

## Description

Terminates the storyboard, releases all related animation variables, and removes the storyboard from the schedule.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method can be called before or after the storyboard starts playing.

This method does not trigger any storyboard events.

## See also

[IUIAnimationManager2::AbandonAllStoryboards](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-abandonallstoryboards)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-conclude)

[IUIAnimationStoryboard2::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-finish)

[IUIAnimationStoryboard2::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-schedule)