# IUIAnimationStoryboard::AddKeyframeAtOffset

## Description

Adds a keyframe at the specified offset from an existing keyframe.

## Parameters

### `existingKeyframe` [in]

The existing keyframe. To add a keyframe at an offset from the start of the storyboard, use the special keyframe [UI_ANIMATION_KEYFRAME_STORYBOARD_START](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd756780(v=vs.85)).

### `offset` [in]

The offset from the existing keyframe at which a new keyframe is to be added.

### `keyframe` [out]

The keyframe to be added.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A keyframe represents a moment in time within a storyboard and can be used to specify the start and end times of transitions. Because keyframes can be added at the ends of transitions, their offsets from the start of the storyboard may not be known until the storyboard is playing.

#### Examples

The following code adds a keyframe at a fixed offset of 0.3 seconds from the keyframe at the start of the storyboard.

```cpp
const UI_ANIMATION_SECONDS offset = 0.3;

UI_ANIMATION_KEYFRAME keyframe1;
hr = pStoryboard->AddKeyframeAtOffset(
       UI_ANIMATION_KEYFRAME_STORYBOARD_START,
       offset,
       &keyframe1
);
```

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeaftertransition)

[IUIAnimationStoryboard::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionatkeyframe)

[IUIAnimationStoryboard::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionbetweenkeyframes)

[UI_ANIMATION_KEYFRAME](https://learn.microsoft.com/windows/win32/api/uianimation/ns-uianimation-__midl___midl_itf_uianimation_0000_0002_0003)