# IUIAnimationTransition::IsDurationKnown

## Description

Determines whether a transition's duration is currently known.

## Return value

Returns S_OK if the duration is known, S_FALSE if the duration is not known, or an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_STORYBOARD_ACTIVE** | The storyboard for this transition is currently in schedule. |

## Remarks

This method should not be called when the storyboard to which the transition has been added is scheduled or playing.

#### Examples

For an example, see [IUIAnimationTransition::GetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-getduration).

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransition::GetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-getduration)