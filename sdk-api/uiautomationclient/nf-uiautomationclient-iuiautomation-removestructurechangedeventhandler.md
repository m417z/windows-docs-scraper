# IUIAutomation::RemoveStructureChangedEventHandler

## Description

Removes a structure-changed event handler.

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element from which to remove the handler.

### `handler` [in]

Type: **[IUIAutomationStructureChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationstructurechangedeventhandler)***

A pointer to the interface that was passed to [IUIAutomation::AddStructureChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addstructurechangedeventhandler).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A UI Automation client should not use multiple threads to add or remove event handlers. Unexpected behavior can result if one event handler is being added or removed while another is being added or removed in the same client process.

It is possible for an event to be delivered to an event handler after the handler has been unsubscribed,
if the event is received simultaneously with the request to unsubscribe the event. The best practice
is to follow the Component Object Model (COM) standard and avoid destroying the event handler object until its reference count
has reached zero. Destroying an event handler immediately after unsubscribing for events may result in an
access violation if an event is delivered late.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)

[RemoveAutomationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removeautomationeventhandler)

[RemoveFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removefocuschangedeventhandler)

[RemovePropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removepropertychangedeventhandler)