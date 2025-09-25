# IUIAnimationVariableIntegerChangeHandler2::OnIntegerValueChanged

## Description

Handles events that occur when the integer value of an animation variable changes in the specified dimension.

## Parameters

### `storyboard` [in]

The storyboard that is animating the animation variable specified by the *variable* parameter.

### `variable` [in]

The animation variable that has been updated.

### `newValue` [in]

The new integer value of the animation variable.

**Note** The rounding mode for an animation variable is specified using the [SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-setroundingmode) method.

### `previousValue` [in]

The previous integer value of the animation variable.

**Note** The rounding mode for an animation variable is specified using the [SetRoundingMode](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-setroundingmode) method.

### `cDimension` [in]

The dimension in which the integer value of the animation variable changed.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method receives updates as **INT32** values.
To receive updates as **DOUBLE** values, use the [OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler2-onvaluechanged) method.

**OnIntegerValueChanged** events might occur less frequently than [OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler2-onvaluechanged) events because values such as 2.2, 2.3, and 2.4 would all be rounded to the same integer.

By default, a call made in a callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**. However, there are exceptions to this default. The following methods can be successfully called from **OnIntegerValueChanged**:

* [GetValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getvalue)
* [GetFinalValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalvalue)
* [GetPreviousValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousvalue)
* [GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getintegervalue)
* [GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalintegervalue)
* [GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousintegervalue)
* [GetCurrentStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getcurrentstoryboard)
* [GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getvariablefromtag)
* [GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstoryboardfromtag)
* [GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-gettag)
* [GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-gettag)

## See also

[IUIAnimationVariableChangeHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariablechangehandler2)

[IUIAnimationVariableIntegerChangeHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariableintegerchangehandler2)

[OnValueChanged](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariablechangehandler2-onvaluechanged)

[SetVariableIntegerChangeHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-setvariableintegerchangehandler)

[UI_ANIMATION_ROUNDING_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_rounding_mode)