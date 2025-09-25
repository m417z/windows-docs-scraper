# IUIAutomationWindowPattern::WaitForInputIdle

## Description

Causes the calling code to block for the specified time or until the associated process enters an idle state, whichever completes first.

## Parameters

### `milliseconds` [in]

Type: **int**

The amount of time, in milliseconds, to wait for the associated process to become idle.

### `success` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Receives the result: **TRUE** if the window has entered the idle state, or **FALSE** if the time-out occurred.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationWindowPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationwindowpattern)