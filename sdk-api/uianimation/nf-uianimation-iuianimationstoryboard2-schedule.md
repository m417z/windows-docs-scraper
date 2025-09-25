# IUIAnimationStoryboard2::Schedule

## Description

Directs the storyboard to schedule itself for play.

## Parameters

### `timeNow` [in]

The current time.

### `schedulingResult` [out, optional]

The result of the scheduling request.
You can omit this parameter from calls to this method.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method directs a storyboard to try to add itself to the schedule of playing storyboards, using these rules:

* If there are no playing storyboards animating any of the same animation variables, the attempt succeeds and the storyboard starts playing immediately.
* If the storyboard has priority to cancel, trim, conclude, or compress conflicting storyboards, the attempt to schedule succeeds and the storyboard starts playing as soon as possible.
* If the storyboard does not have priority, the attempt fails and the *schedulingResult* parameter is set to [UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result).

If this method is called from a handler for [OnStoryboardStatusChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboardeventhandler-onstoryboardstatuschanged) events, the *schedulingResult* parameter is set to **UI_ANIMATION_SCHEDULING_DEFERRED**. The only way to determine whether the storyboard is successfully scheduled is to set a storyboard event handler and check whether the storyboard's status ever becomes [UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result).

It is possible to reuse a storyboard by calling **Schedule** again after its status has reached [UI_ANIMATION_STORYBOARD_READY](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status). An attempt to schedule a storyboard when it is in any state other than **UI_ANIMATION_STORYBOARD_BUILDING** or **UI_ANIMATION_STORYBOARD_READY** fails, and *schedulingResult* is set to [UI_ANIMATION_SCHEDULING_ALREADY_SCHEDULED](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result).

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-abandon)

[IUIAnimationStoryboard2::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-conclude)

[IUIAnimationStoryboard2::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-finish)

[IUIAnimationStoryboard2::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-getstatus)

[IUIAnimationTimer::GetTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-gettime)

[UI_ANIMATION_SCHEDULING_RESULT](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_scheduling_result)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)