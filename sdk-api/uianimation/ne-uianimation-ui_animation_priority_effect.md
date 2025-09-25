# UI_ANIMATION_PRIORITY_EFFECT enumeration

## Description

Defines potential effects on a storyboard if a priority comparison returns false.

## Constants

### `UI_ANIMATION_PRIORITY_EFFECT_FAILURE:0`

This storyboard might not be successfully scheduled.

### `UI_ANIMATION_PRIORITY_EFFECT_DELAY:1`

The storyboard will be scheduled, but might start playing later.

## Remarks

This enumeration is used as the *priorityEffect* parameter of [IUIAnimationPriorityComparison::HasPriority](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority), informing the client of the potential effect on the storyboard to be scheduled when the return value is false (S_FALSE). UI_ANIMATION_PRIORITY_EFFECT_FAILURE means that the attempt to schedule the storyboard might fail if the return value is false. UI_ANIMATION_PRIORITY_EFFECT_DELAY means that the attempt to schedule the storyboard will succeed, but if the return value is false, the storyboard could play later than it would otherwise.

 This enumeration can help an application decide how aggressive to be about reducing latency in the UI. For example, if the application returns true when the effect is UI_ANIMATION_PRIORITY_EFFECT_DELAY, then other animations might get canceled or compressed even though doing so was not strictly necessary to play a new animation within the application-specified longest acceptable delay.

## See also

[IUIAnimationPriorityComparison::HasPriority](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority)