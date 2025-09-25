# IUIAnimationStoryboard::RepeatBetweenKeyframes

## Description

Creates a loop between two specified keyframes.

## Parameters

### `startKeyframe` [in]

The keyframe at which the loop is to begin.

### `endKeyframe` [in]

The keyframe at which the loop is to end. It must not be possible for *endKeyframe* to occur earlier in the storyboard than *startKeyframe*.

### `repetitionCount` [in]

The number of times the loop is to be repeated; this parameter must be 0 or a positive number.
Use [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) to repeat the loop indefinitely until the storyboard is trimmed or concluded.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_START_KEYFRAME_AFTER_END** | The start keyframe might occur after the end keyframe. |
| **UI_E_END_KEYFRAME_NOT_DETERMINED** | It might not be possible to determine the end keyframe time when the start keyframe is reached. |
| **UI_E_LOOPS_OVERLAP** | Two repeated portions of a storyboard might overlap. |

## Remarks

This method directs a storyboard to play the interval between the given keyframes repeatedly before playing the remainder of the storyboard. If a finite repetition count is specified, the loop always plays that number of times. If [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) is specified, the loop repeats until the storyboard is concluded, in which case the current iteration of the loop completes and the remainder of the storyboard plays. A storyboard that loops indefinitely also ends if it is truncated.

Nested and overlapping loops are not supported.

A keyframe represents a moment in time within a storyboard and can be used to specify the start or end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeaftertransition)

[IUIAnimationStoryboard::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeatoffset)