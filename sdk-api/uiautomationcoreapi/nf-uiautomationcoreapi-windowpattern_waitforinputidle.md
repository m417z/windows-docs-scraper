# WindowPattern_WaitForInputIdle function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Causes the calling code to block for the specified time or until the associated process enters an idle state, whichever completes first.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

### `milliseconds` [in]

Type: **int**

The number of milliseconds to wait before retrieving *pResult*.

### `pResult` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**TRUE** if the window is ready to accept user input; otherwise **FALSE**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

This method is typically used in conjunction with the handling of a WindowOpenedEvent
(*Window_WindowOpened_Event_GUID*).
The implementation is dependent on the underlying application framework;
therefore this method may return some time after the window is ready for user input.
The calling code should not rely on this method to ascertain exactly when the window has become idle.
Use the value of *pResult* to determine if the window is ready for input or if the method timed out.