# UI_ANIMATION_STORYBOARD_STATUS enumeration

## Description

Defines the status for a storyboard.

## Constants

### `UI_ANIMATION_STORYBOARD_BUILDING:0`

The storyboard has never been scheduled.

### `UI_ANIMATION_STORYBOARD_SCHEDULED:1`

The storyboard is scheduled to play.

### `UI_ANIMATION_STORYBOARD_CANCELLED:2`

The storyboard was canceled.

### `UI_ANIMATION_STORYBOARD_PLAYING:3`

The storyboard is currently playing.

### `UI_ANIMATION_STORYBOARD_TRUNCATED:4`

The storyboard was truncated.

### `UI_ANIMATION_STORYBOARD_FINISHED:5`

The storyboard has finished playing.

### `UI_ANIMATION_STORYBOARD_READY:6`

The storyboard is built and ready for scheduling.

### `UI_ANIMATION_STORYBOARD_INSUFFICIENT_PRIORITY:7`

Scheduling the storyboard failed because a scheduling conflict occurred and the currently scheduled storyboard has higher priority.

## Remarks

Unless [IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus) is called from a handler for [OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged) events, it returns only the following status values:

* UI_ANIMATION_STORYBOARD_BUILDING
* UI_ANIMATION_STORYBOARD_SCHEDULED
* UI_ANIMATION_STORYBOARD_PLAYING
* UI_ANIMATION_STORYBOARD_READY

All status values can be passed to [IUIAnimationStoryboardEventHandler::OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged).

The following diagram illustrates the transitions between these states.

![Diagram that shows how the animation manager schedules the storyboard and manages the animation.](https://learn.microsoft.com/windows/win32/api/uianimation/images/StateDiagram.png)

## See also

[IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus)

[IUIAnimationStoryboardEventHandler::OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged)