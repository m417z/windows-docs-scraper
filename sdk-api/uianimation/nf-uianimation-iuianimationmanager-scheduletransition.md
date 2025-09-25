# IUIAnimationManager::ScheduleTransition

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

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method schedules a new storyboard by creating the storyboard, applying the specified transition to the specified variable, and then scheduling the storyboard.

#### Examples

The following example creates a storyboard for a specified transition and animation variable.

```cpp
// Get the current time and schedule a single-transition storyboard

UI_ANIMATION_SECONDS secondsNow;
hr = m_pAnimationTimer->GetTime(
    &secondsNow
    );
if (SUCCEEDED(hr))
{
    hr = m_pAnimationManager->ScheduleTransition(
        m_pAnimationVariableY,
        pTransitionParabolic,
        secondsNow
        );
    ...
}

```

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationTimer::GetTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-gettime)

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransitionLibrary](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary)

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)