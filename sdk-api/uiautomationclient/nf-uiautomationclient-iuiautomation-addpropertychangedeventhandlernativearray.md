# IUIAutomation::AddPropertyChangedEventHandlerNativeArray

## Description

Registers a method that handles a native array of property-changed events.

**Note** Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element associated with the event handler.

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and children.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

Type: **[IUIAutomationPropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationpropertychangedeventhandler)***

A pointer to the object that handles the event.

### `propertyArray` [in]

Type: **PROPERTYID***

A pointer to the identifiers of the UI Automation properties of interest. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `propertyCount` [in]

Type: **int**

The number of property identifiers in *propertyArray*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## example

For code examples that show how to implement interfaces that enable clients to receive and handle Microsoft UI Automation events (including AddPropertyChangedEventHandlerNativeArray), see [How to Implement Event Handlers](https://learn.microsoft.com/windows/win32/winauto/uiauto-howto-implement-event-handlers).

## Remarks

The UI item specified by *element* might not support the properties specified by the *propertyArray* parameter.

This method serves the same purpose as [IUIAutomation::AddPropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addpropertychangedeventhandler), but takes a normal array of property identifiers instead of a SAFEARRAY.

A UI Automation client should not use multiple threads to add or remove event handlers. Unexpected behavior can result if one event handler is being added or removed while another is being added or removed in the same client process.

## See also

[AddPropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addpropertychangedeventhandler)

[Caching UI Automation Properties and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-cachingforclients)

**Conceptual**

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

**Reference**

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)

[RemovePropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removepropertychangedeventhandler)

[Subscribing to UI Automation Events](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-eventsforclients)

[Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading)