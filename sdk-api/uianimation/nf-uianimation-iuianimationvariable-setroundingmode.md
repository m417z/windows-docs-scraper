# IUIAnimationVariable::SetRoundingMode

## Description

Specifies the rounding mode for the animation variable.

## Parameters

### `mode` [in]

The rounding mode for the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

An animation variable's rounding mode determines how a floating-point value is converted to an integer.
The default mode for each variable is **UI_ANIMATION_ROUNDING_NEAREST**.

#### Examples

For an example, see [Create Animation Variables](https://learn.microsoft.com/windows/desktop/UIAnimation/create-animation-variables).

## See also

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getfinalintegervalue)

[IUIAnimationVariable::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getintegervalue)

[IUIAnimationVariable::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-getpreviousintegervalue)

[UI_ANIMATION_ROUNDING_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_rounding_mode)