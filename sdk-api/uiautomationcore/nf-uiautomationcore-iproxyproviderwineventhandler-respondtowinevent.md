# IProxyProviderWinEventHandler::RespondToWinEvent

## Description

Handles a WinEvent.

## Parameters

### `idWinEvent` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the incoming WinEvent. For a list of WinEvent IDs, see [Event Constants](https://learn.microsoft.com/windows/desktop/WinAuto/event-constants).

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the window for which the WinEvent was fired. This should also be the window for which the proxy was created.

### `idObject` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The object identifier (OBJID_*) of the accessible object associated with the event. For a list of object identifiers, see [Object Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers).

### `idChild` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The child identifier of the element associated with the event, or **CHILDID_SELF** if the element is not a child.

### `pSink` [in]

Type: **[IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink)***

A pointer to the [IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink) interface provided by the UI Automation core. Any event that the proxy needs to raise in response to the WinEvent being handled should be added to the sink.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The provider should review the event data. If the provider needs to raise a UI Automation event in response, the data for that event should be added to the *pSink* event sink.

## See also

[IProxyProviderWinEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventhandler)

[IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink)

**Reference**