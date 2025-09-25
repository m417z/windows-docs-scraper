# IFileIsInUse::GetSwitchToHWND

## Description

Retrieves the handle of the top-level window of the application that is using the file.

## Parameters

### `phwnd` [out]

Type: **HWND***

A pointer to an **HWND** value that, when this method returns successfully, receives the window handle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only files that return the [capability flag](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileisinuse-getcapabilities) OF_CAP_CANSWITCHTO can be switched to.