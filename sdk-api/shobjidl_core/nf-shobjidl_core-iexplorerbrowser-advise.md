# IExplorerBrowser::Advise

## Description

Initiates a connection with [IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser) for event callbacks.

## Parameters

### `psbe` [in]

Type: **[IExplorerBrowserEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowserevents)***

A pointer to the [IExplorerBrowserEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowserevents) interface of the object to be advised of [IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser) events.

### `pdwCookie` [out]

Type: **DWORD***

When this method returns, contains a token that uniquely identifies the event listener. This allows several event listeners to be subscribed at a time.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by an implementer of [IExplorerBrowserEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowserevents). The implementer (listener) is advised of ExplorerBrowser view and navigation events by callback of the methods of **IExplorerBrowserEvents**.

Call **IExplorerBrowser::Advise** to initiate an advisory connection prior to the first [IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser) navigation. Callbacks to event listeners are made as the browser is browsing.

The first browse happens synchronously to a call on [IExplorerBrowser::BrowseToObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-browsetoobject), or a similar method. Future callbacks happen asynchronously, as the browser browses.

When the connection is no longer needed, call method [IExplorerBrowser::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-unadvise) to terminate the connection.

## See also

[IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser)

[OnNavigationComplete](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationcomplete)

[OnNavigationFailed](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationfailed)

[OnViewCreated](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onviewcreated)