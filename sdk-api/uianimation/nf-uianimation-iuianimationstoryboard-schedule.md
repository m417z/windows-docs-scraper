# IUIAnimationStoryboard::Schedule

## Description

Directs the storyboard to schedule itself for play.

## Parameters

### `timeNow` [in]

The current time.

### `schedulingResult` [out, optional]

The result of the scheduling request.
This parameter can be omitted from calls to this method.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method directs a storyboard to attempt to add itself to the schedule of playing storyboards. The rules are as follows:

* If there are no playing storyboards animating any of the same animation variables, the attempt succeeds and the storyboard starts playing immediately.
* If the storyboard has priority to cancel, trim, conclude, or compress conflicting storyboards, the attempt to schedule succeeds and the storyboard begins playing as soon as possible.
* If the storyboard does not have priority, the attempt fails and the *schedulingResult* parameter is set to **UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY**.

If this method is called from a handler for [OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged) events, the *schedulingResult* parameter is set to **UI_ANIMATION_SCHEDULING_DEFERRED**. The only way to determine whether the storyboard is successfully scheduled is to set a storyboard event handler and check whether the storyboard's status ever becomes **UI_ANIMATION_STORYBOARD_INSUFFICIENT_PRIORITY**.

It is possible reuse a storyboard by calling **Schedule** again after its status has reached **UI_ANIMATION_STORYBOARD_READY**. An attempt to schedule a storyboard when it is in any state other than **UI_ANIMATION_STORYBOARD_BUILDING** or **UI_ANIMATION_STORYBOARD_READY** fails, and *schedulingResult* is set to **UI_ANIMATION_SCHEDULING_ALREADY_SCHEDULED**.

#### Examples

The following example gets the current time and schedules the storyboard. For an additional example, see [Schedule a Storyboard](https://learn.microsoft.com/windows/desktop/UIAnimation/scheduling-a-storyboard).

```cpp
// Get the current time and schedule the storyboard
UI_ANIMATION_SECONDS secondsNow;
hr = m_pAnimationTimer->GetTime(
    &secondsNow
    );
if (SUCCEEDED(hr))
{
    UI_ANIMATION_SCHEDULING_RESULT schedulingResult;
    hr = pStoryboard->Schedule(
        secondsNow,
        &schedulingResult
        );
    if (SUCCEEDED(hr))
    {
        if (schedulingResult == UI_ANIMATION_SCHEDULING_SUCCEEDED)
        {
            ...
        }
        else
        {
            ...
        }
    }
}
```

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-abandon)

[IUIAnimationStoryboard::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-conclude)

[IUIAnimationStoryboard::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-finish)

[IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus)

[IUIAnimationTimer::GetTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-gettime)

[UI_ANIMATION_SCHEDULING_RESULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)