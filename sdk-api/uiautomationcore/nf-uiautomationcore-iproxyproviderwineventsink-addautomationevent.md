# IProxyProviderWinEventSink::AddAutomationEvent

## Description

Raises a Microsoft UI Automation event.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

A pointer to the provider for the element that will raise the event.

### `id` [in]

Type: **EVENTID**

The identifier of the event that will be raised. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink)