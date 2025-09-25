# IUIAnimationVariableIntegerChangeHandler::OnIntegerValueChanged

## Description

Handles events that occur when the value of an animation variable changes.

This method receives updates as **INT32** values. To receive updates as **DOUBLE** values, use the [IUIAnimationVariableChangeHandler::OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler-onvaluechanged) method.

## Parameters

### `storyboard` [in]

The storyboard that is animating the animation variable specified by the *variable* parameter.

### `variable` [in]

The animation variable that has been updated.

### `newValue` [in]

The new value of the animation variable, rounded according to the variable's rounding mode.

### `previousValue` [in]

The previous value of the animation variable, rounded according to the variable's rounding mode.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The rounding mode for an animation variable is specified using the [IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode) method.

**OnIntegerValueChanged** events might occur less frequently than [OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler-onvaluechanged) events because values such as 2.2, 2.3, 2.4 would all be rounded to the same integer.

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnIntegerValueChanged**:

* [IUIAnimationVariable::GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getcurrentstoryboard)
* [IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)
* [IUIAnimationVariable::GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalvalue)
* [IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)
* [IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)
* [IUIAnimationVariable::GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousvalue)
* [IUIAnimationVariable::GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getvalue)
* [IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)
* [IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)
* [IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)
* [IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)

## See also

[IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)

[IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)

[IUIAnimationVariable::SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setroundingmode)

[IUIAnimationVariable::SetVariableIntegerChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-setvariableintegerchangehandler)

[IUIAnimationVariableChangeHandler::OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler-onvaluechanged)

[IUIAnimationVariableIntegerChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariableintegerchangehandler)

[UI_ANIMATION_ROUNDING_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_rounding_mode)