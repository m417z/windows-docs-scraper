# IUIAnimationStoryboard2::RepeatBetweenKeyframes

## Description

Creates a loop between two keyframes.

## Parameters

### `startKeyframe` [in]

The keyframe at which the loop is to begin.

### `endKeyframe` [in]

The keyframe at which the loop is to end. *endKeyframe* must not occur earlier in the storyboard than *startKeyframe*.

### `cRepetition` [in]

The number of times the loop is to be repeated; the last iteration of a loop can terminate fractionally between keyframes. A value of zero indicates that the specified portion of a storyboard will not be played. A value of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) indicates that the loop will repeat indefinitely until the storyboard is trimmed or concluded.

### `repeatMode` [in]

The pattern for the loop iteration.

A value of [UI_ANIMATION_REPEAT_MODE_ALTERNATE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_repeat_mode) (1) specifies that the start of the loop must alternate between keyframes (k1->k2, k2->k1, k1->k2, and so on).

A value of [UI_ANIMATION_REPEAT_MODE_NORMAL](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_repeat_mode) (0) specifies that the start of the loop must begin with the first keyframe (k1->k2, k1->k2, k1->k2, and so on).

**Note** If *repeatMode* has a value of [UI_ANIMATION_REPEAT_MODE_ALTERNATE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_repeat_mode) (1) and *cRepetition* has a value of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1), the loop terminates on the end keyframe.

### `pIterationChangeHandler` [in]

The handler for each loop iteration event. The default value is 0.

### `id` [in]

The loop ID to pass to *pIterationChangeHandler*. The default value is 0.

### `fRegisterForNextAnimationEvent` [in]

If true, specifies that *pIterationChangeHandler* will be incorporated into the estimate of the time interval until the next animation event that is returned by the [IUIAnimationManager2::EstimateNextEventTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-estimatenexteventtime) method. The default value is 0, or false.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method directs a storyboard to play the interval between the given keyframes repeatedly before playing the remainder of the storyboard. If a finite repetition count is specified, the loop always plays that number of times. If [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) (-1) is specified, the loop repeats until the storyboard is concluded, in which case the current iteration of the loop completes and the remainder of the storyboard plays. A storyboard that loops indefinitely also ends if it is truncated.

Nested and overlapping loops are not supported.

A keyframe represents a moment in time within a storyboard and can be used to specify the start or end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeaftertransition)

[IUIAnimationStoryboard2::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeatoffset)