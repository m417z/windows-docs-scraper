# UI_ANIMATION_SCHEDULING_RESULT enumeration

## Description

Defines results for storyboard scheduling.

## Constants

### `UI_ANIMATION_SCHEDULING_UNEXPECTED_FAILURE:0`

Scheduling failed for an unexpected reason.

### `UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY:1`

Scheduling failed because
a scheduling conflict occurred and the currently scheduled storyboard has higher priority.
For more information, see [IUIAnimationPriorityComparison::HasPriority](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

### `UI_ANIMATION_SCHEDULING_ALREADY_SCHEDULED:2`

Scheduling failed because
the storyboard is already scheduled.

### `UI_ANIMATION_SCHEDULING_SUCCEEDED:3`

Scheduling succeeded.

### `UI_ANIMATION_SCHEDULING_DEFERRED:4`

Scheduling is deferred and will be attempted when the current callback completes.

## Remarks

[IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule) returns UI_ANIMATION_SCHEDULING_DEFERRED only if the application attempts to schedule a storyboard during a callback to [IUIAnimationStoryboardEventHandler::OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged).

## See also

[IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule)