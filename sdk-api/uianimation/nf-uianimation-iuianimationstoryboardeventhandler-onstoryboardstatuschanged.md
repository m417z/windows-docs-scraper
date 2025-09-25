# IUIAnimationStoryboardEventHandler::OnStoryboardStatusChanged

## Description

Handles events that occur when a storyboard's status changes.

## Parameters

### `storyboard` [in]

The storyboard whose status has changed.

### `newStatus` [in]

The new status.

### `previousStatus` [in]

The previous status.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnStoryboardStatusChanged**:

* [IUIAnimationManager::CreateAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-createanimationvariable)
* [IUIAnimationManager::CreateStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-createstoryboard)
* [IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)
* [IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)
* [IUIAnimationStoryboard::Abandon](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-abandon)
* [IUIAnimationStoryboard::AddKeyframeAtOffset](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeatoffset)
* [IUIAnimationStoryboard::AddKeyframeAfterTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addkeyframeaftertransition)
* [IUIAnimationStoryboard::AddTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransition)
* [IUIAnimationStoryboard::AddTransitionAtKeyframe](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionatkeyframe)
* [IUIAnimationStoryboard::AddTransitionBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-addtransitionbetweenkeyframes)
* [IUIAnimationStoryboard::Conclude](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-conclude)
* [IUIAnimationStoryboard::Finish](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-finish)
* [IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)
* [IUIAnimationStoryboard::HoldVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-holdvariable)
* [IUIAnimationStoryboard::RepeatBetweenKeyframes](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-repeatbetweenkeyframes)
* [IUIAnimationStoryboard::SetLongestAcceptableDelay](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-setlongestacceptabledelay)
* [IUIAnimationStoryboard::SetStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-setstoryboardeventhandler)
* [IUIAnimationStoryboard::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-settag)
* [IUIAnimationStoryboard::Schedule](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-schedule)
* [IUIAnimationTransition::GetDuration](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-getduration)
* [IUIAnimationTransition::IsDurationKnown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-isdurationknown)
* [IUIAnimationTransition::SetInitialValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-setinitialvalue)
* [IUIAnimationTransition::SetInitialVelocity](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-setinitialvelocity)
* [IUIAnimationVariable::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getcurrentstoryboard)
* [IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)
* [IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)
* [IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)
* [IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)
* [IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)
* [IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)
* [IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)
* [IUIAnimationVariable::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-settag)

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-getstatus)

[IUIAnimationStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler)

[UI_ANIMATION_STORYBOARD_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_storyboard_status)