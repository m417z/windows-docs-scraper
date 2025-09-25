# IWindowProvider::WaitForInputIdle

## Description

Causes the calling code to block for the specified time or until the associated process enters an idle state, whichever completes first.

## Parameters

### `milliseconds` [in]

Type: **int**

The amount of time, in milliseconds, to wait for the associated process to become idle.
The maximum is Int32.MaxValue.

### `pRetVal` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Receives **TRUE** if the window has entered the idle state; **FALSE** if the time-out occurred.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is typically used in conjunction with the handling of a [UIA_Window_WindowOpenedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).
The implementation is dependent on the underlying application framework;
therefore this method might return some time after the window is ready for user input.
The calling code should not rely on this method to ascertain exactly when the window has become idle.
Use the value of *pRetVal* to determine if the window is ready for input or if the method timed out.

## See also

[IWindowProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iwindowprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)