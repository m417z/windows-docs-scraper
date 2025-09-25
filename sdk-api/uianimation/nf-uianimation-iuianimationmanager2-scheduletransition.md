# IUIAnimationManager2::ScheduleTransition

## Description

Creates and schedules a single-transition storyboard.

## Parameters

### `variable` [in]

The animation variable.

### `transition` [in]

A transition to be applied to the animation variable.

### `timeNow` [in]

The current system time.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method schedules a new storyboard by creating the storyboard, applying the specified transition to the specified variable, and then scheduling the storyboard.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationTimer::GetTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-gettime)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)