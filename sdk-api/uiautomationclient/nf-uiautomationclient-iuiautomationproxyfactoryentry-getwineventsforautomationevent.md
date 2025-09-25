# IUIAutomationProxyFactoryEntry::GetWinEventsForAutomationEvent

## Description

Retrieves the list of WinEvents that are mapped to a specific Microsoft UI Automation event. If an element represented by this proxy raises one the listed WinEvents, the proxy handles it.

## Parameters

### `eventId` [in]

Type: **EVENTID**

The event identifier. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `winEvents` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to the list of WinEvents that map to this event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IUIAutomationProxyFactoryEntry](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactoryentry)

**Reference**

[SetWinEventsForAutomationEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationproxyfactoryentry-setwineventsforautomationevent)