# UiaRaiseAutomationEvent function

## Description

Notifies listeners of an event.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider element where the event occurred.

### `id` [in]

Type: **EVENTID**

The identifier of the event to be raised. For a list of event IDs, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function increments the reference counter of the *pProvider* interface, and UI Automation decrements the reference counter when the event handers finish processing the event.