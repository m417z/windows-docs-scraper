# IUIAnimationVariable2::SetRoundingMode

## Description

Sets the rounding mode of the animation variable.

## Parameters

### `mode` [in]

The rounding mode.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

An animation variable's rounding mode determines how a floating-point value is converted to an integer.
The default mode for each variable is **UI_ANIMATION_ROUNDING_NEAREST**.

## See also

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)

[IUIAnimationVariable2::GetFinalIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getfinalintegervalue)

[IUIAnimationVariable2::GetIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getintegervalue)

[IUIAnimationVariable2::GetPreviousIntegerValue](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-getpreviousintegervalue)

[UI_ANIMATION_ROUNDING_MODE](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_rounding_mode)