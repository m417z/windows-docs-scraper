# IUIAutomationProxyFactoryEntry::SetWinEventsForAutomationEvent

## Description

Maps Microsoft UI Automation events to WinEvents.

## Parameters

### `eventId` [in]

Type: **EVENTID**

The event identifier. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `winEvents` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

The list of WinEvents that map to this event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a client application subscribes to a UI Automation event, the UI Automation core also listens for WinEvents that map to this event. For example, suppose that [UIA_Invoke_InvokedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) is mapped to [EVENT_OBJECT_INVOKED](https://learn.microsoft.com/windows/desktop/WinAuto/event-constants). When **EVENT_OBJECT_INVOKED** is raised, the client instantiates the proxy and calls [RespondToWinEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iproxyproviderwineventhandler-respondtowinevent) on that proxy. In the implementation of **RespondToWinEvent**, the proxy calls [AddAutomationEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iproxyproviderwineventsink-addautomationevent). The core then raises the corresponding UI Automation event.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[GetWinEventsForAutomationEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationproxyfactoryentry-getwineventsforautomationevent)

[IUIAutomationProxyFactoryEntry](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactoryentry)

**Reference**