# IUIAnimationManager::CreateStoryboard

## Description

Creates a new storyboard.

## Parameters

### `storyboard` [out]

The new storyboard.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Storyboards can specify complex coordinated updates to many animation variables. These updates happen in sequence or in parallel, and they are guaranteed to remain synchronized within the storyboard. A storyboard is created, populated with transitions on animation variables, and then scheduled.

#### Examples

For an example, see [Create a Storyboard and Add Transitions](https://learn.microsoft.com/windows/desktop/UIAnimation/updating---timer-driven-animation).

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)