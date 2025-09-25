# IUIAnimationStoryboard2::Conclude

## Description

Completes the current iteration of a keyframe loop that is in progress (where the loop is set to [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely)), terminates the loop, and continues with the storyboard.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method specifies that any subsequent keyframe loops that have a repetition count of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) will be skipped while the remainder of the storyboard is played.

An iteration of a keyframe loop that is in progress will be completed before the remainder of the storyboard plays.

If this method is called at the end of an alternating keyframe loop iteration, the loop is terminated with the loop value set to the ending loop value.

 If this method is called at the end of a non-alternating keyframe loop iteration, where "loop wrapping" results in the loop value being set to the starting value of the next iteration, the loop is executed once more in order for the loop value to be set to the ending loop value.

For alternating keyframe loops, each iteration has a starting value that is equivalent to the ending value of the preceding loop. In this case, "loop wrapping" is not an issue.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)