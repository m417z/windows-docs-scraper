# IExplorerBrowserEvents::OnNavigationPending

## Description

Notifies clients of a pending Explorer browser navigation to a Shell folder.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A PIDL that specifies the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Explorer browser calls this method before it navigates to a folder, that is, before calling [IExplorerBrowserEvents::OnNavigationFailed](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationfailed) or [IExplorerBrowserEvents::OnNavigationComplete](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationcomplete).

Returning any failure code from this method, including E_NOTIMPL, will cancel the navigation.