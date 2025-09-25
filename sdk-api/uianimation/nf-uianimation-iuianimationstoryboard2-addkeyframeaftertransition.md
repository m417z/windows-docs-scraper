# IUIAnimationStoryboard2::AddKeyframeAfterTransition

## Description

Adds a keyframe at the end of the specified transition.

## Parameters

### `transition` [in]

The transition after which a keyframe is to be added.

### `keyframe` [out]

The keyframe to be added.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_NOT_IN_STORYBOARD** | The transition has not been added to the storyboard. |

See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A keyframe represents a moment in time within a storyboard and can be used to specify the start and end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeatoffset)

[IUIAnimationStoryboard2::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransition)

[IUIAnimationStoryboard2::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionatkeyframe)

[IUIAnimationStoryboard2::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionbetweenkeyframes)

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)

[UI_ANIMATION_KEYFRAME](https://learn.microsoft.com/windows/win32/api/uianimation/ns-uianimation-__midl___midl_itf_uianimation_0000_0002_0003)