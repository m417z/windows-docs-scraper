# IUIAnimationStoryboard::Conclude

## Description

Completes the current iteration of a keyframe loop that is in progress (where the loop is set to **UI_ANIMATION_REPEAT_INDEFINITELY**), terminates the loop, and continues with the storyboard.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method specifies that any subsequent keyframe loops that have a repetition count of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) will be skipped while the remainder of the storyboard is played.

An iteration of a keyframe loop that is in progress will be completed before the remainder of the storyboard plays.

If this method is called at the end of a keyframe loop iteration, the loop is terminated and the loop value is set to the starting loop value.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-abandon)

[IUIAnimationStoryboard::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-finish)

[IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule)