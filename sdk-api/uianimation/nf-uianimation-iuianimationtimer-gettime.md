# IUIAnimationTimer::GetTime

## Description

Gets the current time.

## Parameters

### `seconds` [out]

The current time, in [UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds).

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

This method can be used in both the application-driven and timer-driven configurations to retrieve the system time in [UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds), the units used throughout the Windows Animation API.

#### Examples

For an example, see [Update the Animation Manager and Draw Frames](https://learn.microsoft.com/windows/desktop/UIAnimation/introducing-windows-animation-manager).

## See also

[IUIAnimationTimer](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimer)

[UI_ANIMATION_SECONDS](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds)