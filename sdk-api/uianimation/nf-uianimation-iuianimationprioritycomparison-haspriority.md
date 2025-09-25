# IUIAnimationPriorityComparison::HasPriority

## Description

Determines whether a new storyboard has priority over a scheduled storyboard.

## Parameters

### `scheduledStoryboard` [in]

The currently scheduled storyboard.

### `newStoryboard` [in]

The new storyboard that is interrupting the scheduled storyboard specified in *scheduledStoryboard*.

### `priorityEffect` [in]

 The potential effect on *newStoryboard* if *scheduledStoryboard* has a higher priority.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | *newStoryboard* has priority. |
| **S_FALSE** | *scheduledStoryboard* has priority. |

## Remarks

A single animation variable can be included in multiple storyboards, but multiple storyboards cannot animate the same variable at the same time.
If a new storyboard attempts to animate one or more variables that are currently scheduled for animation by a different storyboard, a scheduling conflict occurs.
To determine which storyboard has priority, the animation manager can call **HasPriority** on one or more priority comparison handlers provided by the application.

Registering priority comparison objects is optional. By default, all storyboards can be trimmed, concluded or compressed to prevent failure, but none can be canceled, and by default no storyboards will be canceled or trimmed to prevent a delay.

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **HasPriority**:

* [IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)
* [IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)
* [IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)
* [IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)

### Contention Management

To resolve a scheduling conflict, the animation manager has the following options:

* Cancel the scheduled storyboard if it has not started playing and the priority comparison object registered with [IUIAnimationManager::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcancelprioritycomparison) returns **S_OK**. Canceled storyboards are completely removed from the schedule.
* Trim the scheduled storyboard if the priority comparison object registered with [IUIAnimationManager::SetTrimPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-settrimprioritycomparison) returns **S_OK**. If the new storyboard trims the scheduled storyboard, the scheduled storyboard can no longer affect a variable when the new storyboard begins to animate that variable.
* Conclude the scheduled storyboard if the scheduled storyboard contains a loop with a repetition count of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) and the priority comparison object registered with [IUIAnimationManager::SetConcludePriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setconcludeprioritycomparison) returns **S_OK**. If the storyboard is concluded, the current repetition of the loop completes, and the reminder of the storyboard then plays.
* Compress the scheduled storyboard, and any other storyboards animating the same variables, if the priority comparison object registered with [IUIAnimationManager::SetCompressPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcompressprioritycomparison) returns **S_OK** for all scheduled storyboards that might be affected by the compression. When the storyboards are compressed, time is temporarily accelerated for affected storyboards, so they play faster.

If none of the above options is allowed by the priority comparison objects, the attempt to schedule the storyboard fails and Windows Animation returns [UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result) to the calling application.

Note that for the new storyboard to be successfully scheduled, it must begin before its longest acceptable delay has elapsed. This is determined by [IUIAnimationStoryboard::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-setlongestacceptabledelay)  or [IUIAnimationManager::SetDefaultLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setdefaultlongestacceptabledelay) (if neither is called, the default is 0.0 seconds). If the longest acceptable delay is **UI_ANIMATION_SECONDS_EVENTUALLY**, any finite delay will be sufficient.

The *priorityEffect* parameter describes the possible effect on the new storyboard if **HasPriority** were to return S_FALSE. If *priorityEffect* is [UI_ANIMATION_PRIORITY_EFFECT_FAILURE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_priority_effect), it is possible that returning S_FALSE will result in a failure to schedule the new storyboard (it is also possible that the animation manager will be allowed to resolve the conflict in a different way by another priority comparison object). If *priorityEffect* is **UI_ANIMATION_PRIORITY_EFFECT_DELAY**, the only downside of returning S_FALSE is that the storyboard might begin later than it would have had *HasPriority* returned S_OK.

When [UI_ANIMATION_PRIORITY_EFFECT_DELAY](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_priority_effect) is passed to **HasPriority**, the animation manager has already determined that it can schedule the new storyboard such that it will begin before its longest acceptable delay has elapsed, but it is in effect asking the application if the storyboard should begin even earlier. In some scenarios, it might be best to reduce the latency of an animation by returning S_OK. In others, it might be preferable to let scheduled animations complete whenever possible, in which case S_FALSE should be returned. **UI_ANIMATION_PRIORITY_EFFECT_DELAY** is only passed to **HasPriority** when the animation manager is considering canceling or trimming a storyboard.

## See also

[IUIAnimationManager::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcancelprioritycomparison)

[IUIAnimationManager::SetCompressPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcompressprioritycomparison)

[IUIAnimationManager::SetConcludePriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setconcludeprioritycomparison)

[IUIAnimationManager::SetTrimPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-settrimprioritycomparison)

[IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison)

[UI_ANIMATION_PRIORITY_EFFECT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_priority_effect)