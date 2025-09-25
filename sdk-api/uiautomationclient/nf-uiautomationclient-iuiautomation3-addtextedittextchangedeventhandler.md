# IUIAutomation3::AddTextEditTextChangedEventHandler

## Description

Registers a method that handles programmatic text-edit events.

**Note** Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element associated with the event handler.

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `textEditChangeType` [in]

Type: **[TextEditChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-texteditchangetype)**

The specific change type to listen for. Clients register for each text-edit change type separately, so that the UI Automation system can check for registered listeners at run-time and avoid raising events for particular text-edit changes when there are no listeners.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

Type: **[IUIAutomationTextEditTextChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextedittextchangedeventhandler)***

A pointer to the object that handles the programmatic text-edit event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A UI Automation client should not use multiple threads to add or remove event handlers. Unexpected behavior can result if one event handler is being added or removed while another is being added or removed in the same client process.

## See also

[Caching UI Automation Properties and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-cachingforclients)

**Conceptual**

[IUIAutomation3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation3)

**Reference**

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)

[RemoveTextEditTextChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removestructurechangedeventhandler)

[Subscribing to UI Automation Events](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-eventsforclients)

[Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading)