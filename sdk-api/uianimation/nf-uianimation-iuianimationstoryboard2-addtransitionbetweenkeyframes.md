# IUIAnimationStoryboard2::AddTransitionBetweenKeyframes

## Description

Adds a transition between two keyframes.

## Parameters

### `variable` [in]

The animation variable for which the transition is to be added.

### `transition` [in]

The transition to be added.

### `startKeyframe` [in]

A keyframe that specifies the beginning of the new transition.

### `endKeyframe` [in]

A keyframe that specifies the end of the new transition. It must not be possible for *endKeyframe* to appear earlier in the storyboard than *startKeyframe*.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_ALREADY_USED** | This transition has already been added to a storyboard or has been added to a storyboard that has finished playing and been released. |
| **UI_E_TRANSITION_ECLIPSED** | The transition might eclipse the beginning of another transition in the storyboard. |
| **UI_E_START_KEYFRAME_AFTER_END** | The start keyframe might occur after the end keyframe. |

See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method applies the specified transition to the specified variable in the storyboard, with the transition starting and ending at the specified keyframes. If the transition was created with a duration parameter specified, that duration is overwritten with the duration of time between the start and end keyframes. Otherwise, Windows Animation speeds up or slows down the transition as necessary.

A keyframe represents a moment in time within a storyboard and can be used to specify the start and end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

Transitions must be added in the order in which they will be played. A transition may begin playing before the preceding transition in the storyboard has finished, in which case the initial value and velocity seen by the new transition will be determined by the state of the preceding one. It must not be possible for a transition to begin before the start of the preceding transition.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeaftertransition)

[IUIAnimationStoryboard2::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeatoffset)

[IUIAnimationStoryboard2::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransition)

[IUIAnimationStoryboard2::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionatkeyframe)

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)