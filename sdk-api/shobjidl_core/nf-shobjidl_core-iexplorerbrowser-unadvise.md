# IExplorerBrowser::Unadvise

## Description

Terminates an advisory connection.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A connection token previously returned from [IExplorerBrowser::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-advise). Identifies the connection to be terminated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Terminates an advisory connection previously established through method [IExplorerBrowser::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-advise). The *dwCookie* parameter identifies the connection to terminate. Failure to call **IExplorerBrowser::Unadvise**, may result in a memory leak.