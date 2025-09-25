# IUIAutomationRegistrar::RegisterEvent

## Description

Registers a third-party Microsoft UI Automation event.

## Parameters

### `event` [in]

Type: **[UIAutomationEventInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationeventinfo)***

A pointer to a structure that contains information about the event to register.

### `eventId` [out]

Type: **EVENTID***

Receives the event identifier. For a list of event IDs, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event ID can be used in various event methods, and as a WinEvent value for events in [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) implementations.

## See also

[IUIAutomationRegistrar](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationregistrar)