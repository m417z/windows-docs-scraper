# IUIAnimationStoryboard2::AddTransition

## Description

Adds a transition to the storyboard.

## Parameters

### `variable` [in]

The animation variable for which the transition is to be added.

### `transition` [in]

The transition to be added.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_ALREADY_USED** | This transition has already been added to a storyboard. |

See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The **AddTransition** method applies the specified transition to the specified variable in the storyboard. If this is the first transition applied to this variable in this storyboard, the transition begins at the start of the storyboard. Otherwise, the transition is appended to the transition that was most recently added to the variable.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeaftertransition)

[IUIAnimationStoryboard2::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionbetweenkeyframes)

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)