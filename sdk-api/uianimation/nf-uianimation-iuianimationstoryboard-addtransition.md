# IUIAnimationStoryboard::AddTransition

## Description

Adds a transition to the storyboard.

## Parameters

### `variable` [in]

The animation variable for which the transition is to be added.

### `transition` [in]

The transition to be added.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_TRANSITION_ALREADY_USED** | This transition has already been added to a storyboard. |

## Remarks

The **AddTransition** method applies the specified transition to the specified variable in the storyboard. If this is the first transition applied to this variable in this storyboard, the transition begins at the start of the storyboard. Otherwise, the transition is appended to the transition that was most recently added to the variable.

#### Examples

For an example, see [Create a Storyboard and Add Transitions](https://learn.microsoft.com/windows/desktop/UIAnimation/updating---timer-driven-animation).

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeaftertransition)

[IUIAnimationStoryboard::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionbetweenkeyframes)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)