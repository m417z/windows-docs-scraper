# IUIAnimationManager2::EstimateNextEventTime

## Description

Retrieves an estimate of the time interval before the next animation event.

## Parameters

### `seconds` [out]

The estimated time, in seconds.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[UI_ANIMATION_SECONDS_INFINITE](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-seconds-infinite)