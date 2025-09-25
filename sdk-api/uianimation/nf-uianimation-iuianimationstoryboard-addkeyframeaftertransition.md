# IUIAnimationStoryboard::AddKeyframeAfterTransition

## Description

Adds a keyframe at the end of the specified transition.

## Parameters

### `transition` [in]

The transition after which a keyframe is to be added.

### `keyframe` [out]

The keyframe to be added.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See  [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_NOT_IN_STORYBOARD** | The transition has not been added to the storyboard. |

## Remarks

A keyframe represents a moment in time within a storyboard and can be used to specify the start and end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeatoffset)

[IUIAnimationStoryboard::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransition)

[IUIAnimationStoryboard::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionatkeyframe)

[IUIAnimationStoryboard::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionbetweenkeyframes)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)

[UI_ANIMATION_KEYFRAME](https://learn.microsoft.com/windows/win32/api/uianimation/ns-uianimation-__midl___midl_itf_uianimation_0000_0002_0003)