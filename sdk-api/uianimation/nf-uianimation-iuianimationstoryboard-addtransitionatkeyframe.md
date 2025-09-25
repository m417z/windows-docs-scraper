# IUIAnimationStoryboard::AddTransitionAtKeyframe

## Description

Adds a transition that starts at the specified keyframe.

## Parameters

### `variable` [in]

The animation variable for which a transition is to be added.

### `transition` [in]

The transition to be added.

### `startKeyframe` [in]

The keyframe that specifies the beginning of the new transition.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_ALREADY_USED** | This transition has already been added to a storyboard or has been added to a storyboard that has finished playing and been released. |
| **UI_E_TRANSITION_ECLIPSED** | The transition might eclipse the beginning of another transition in the storyboard. |

## Remarks

Transitions must be added in the order in which they will be played. A transition may begin playing before the preceding transition in the storyboard has finished, in which case the initial value and velocity seen by the new transition is determined by the state of the preceding one. A transition should not begin before the start of the preceding transition.

A keyframe represents a moment in time within a storyboard and can be used to specify the start and end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeaftertransition)

[IUIAnimationStoryboard::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeatoffset)

[IUIAnimationStoryboard::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransition)

[IUIAnimationStoryboard::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionbetweenkeyframes)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)