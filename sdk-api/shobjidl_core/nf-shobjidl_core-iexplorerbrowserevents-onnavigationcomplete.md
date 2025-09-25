# IExplorerBrowserEvents::OnNavigationComplete

## Description

Notifies clients that the Explorer browser has successfully navigated to a Shell folder.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A PIDL that specifies the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called after method [IExplorerBrowserEvents::OnViewCreated](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onviewcreated), assuming a successful view creation.

After a navigation and view creation, either **IExplorerBrowserEvents::OnNavigationComplete** or [IExplorerBrowserEvents::OnNavigationFailed](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationfailed) is called depending on whether the destination could be navigated to. For example, a failure to navigate includes a destination that is not reached either because there is no route to the path or the user has canceled.