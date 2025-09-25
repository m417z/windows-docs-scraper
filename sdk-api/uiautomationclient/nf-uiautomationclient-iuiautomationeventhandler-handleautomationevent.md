# IUIAutomationEventHandler::HandleAutomationEvent

## Description

Handles a Microsoft UI Automation event.

## Parameters

### `sender` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element that raised the event.

### `eventId` [in]

Type: **EVENTID**

The event identifier. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that it has subscribed to by using [AddAutomationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addautomationeventhandler).

Adjusting an event handler from within this method is not supported.

## See also

[IUIAutomationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationeventhandler)