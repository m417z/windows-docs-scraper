# IUIAnimationStoryboardEventHandler2::OnStoryboardStatusChanged

## Description

Handles storyboard status change events.

## Parameters

### `storyboard` [in]

The storyboard for which the status has changed.

### `newStatus` [in]

The new status.

### `previousStatus` [in]

The previous status.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnStoryboardStatusChanged**:

* [IUIAnimationManager2::CreateAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-createanimationvariable)
* [IUIAnimationManager2::CreateStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-createstoryboard)
* [IUIAnimationManager2::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstoryboardfromtag)
* [IUIAnimationManager2::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getvariablefromtag)
* [IUIAnimationStoryboard2::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-abandon)
* [IUIAnimationStoryboard2::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeatoffset)
* [IUIAnimationStoryboard2::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addkeyframeaftertransition)
* [IUIAnimationStoryboard2::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransition)
* [IUIAnimationStoryboard2::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionatkeyframe)
* [IUIAnimationStoryboard2::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-addtransitionbetweenkeyframes)
* [IUIAnimationStoryboard2::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-conclude)
* [IUIAnimationStoryboard2::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-finish)
* [IUIAnimationStoryboard2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-gettag)
* [IUIAnimationStoryboard2::HoldVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-holdvariable)
* [IUIAnimationStoryboard2::RepeatBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-repeatbetweenkeyframes)
* [IUIAnimationStoryboard2::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setlongestacceptabledelay)
* [IUIAnimationStoryboard2::SetStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-setstoryboardeventhandler)
* [IUIAnimationStoryboard2::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-settag)
* [IUIAnimationStoryboard2::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-schedule)
* [IUIAnimationTransition2::GetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-getduration)
* [IUIAnimationTransition2::IsDurationKnown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-isdurationknown)
* [IUIAnimationTransition2::SetInitialValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-setinitialvalue)
* [IUIAnimationTransition2::SetInitialVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition2-setinitialvelocity)
* [IUIAnimationVariable2::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getcurrentstoryboard)
* [IUIAnimationVariable2::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalintegervalue)
* [IUIAnimationVariable2::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalvalue)
* [IUIAnimationVariable2::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getintegervalue)
* [IUIAnimationVariable2::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousintegervalue)
* [IUIAnimationVariable2::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousvalue)
* [IUIAnimationVariable2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-gettag)
* [IUIAnimationVariable2::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getvalue)
* [IUIAnimationVariable2::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-settag)

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-getstatus)

[IUIAnimationStoryboardEventHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler2)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)