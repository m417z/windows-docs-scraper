# SetContractDelegateWindow function

## Description

Associates an app window other than the primary foreground window with an app's contracts. Use this function if you are a developer writing a Windows Store app in native C++.

## Parameters

### `hwndSource` [in]

Type: **HWND**

The handle of the app window normally associated with its contracts.

### `hwndDelegate` [in, optional]

Type: **HWND**

The handle of another of the app's windows that will act as the contract delegate for *hwndSource*. Set this value to **NULL** to remove the delegate connection.

## Remarks

This is an inline function, with the source code included in the header file. It is not included in a .lib or .dll file.

## See also

[GetContractDelegateWindow](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj152005(v=vs.85))