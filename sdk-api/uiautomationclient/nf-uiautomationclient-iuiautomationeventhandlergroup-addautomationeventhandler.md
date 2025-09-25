# IUIAutomationEventHandlerGroup::AddAutomationEventHandler

## Description

Registers a method that handles Microsoft UI Automation events.

**Important** UI Automation clients should use the handler group methods to register event listeners instead of individual event registration methods defined in the various [IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation) namespaces.

## Parameters

### `eventId` [in]

The identifier of the event that the method handles. For a list of event IDs, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `scope` [in]

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `cacheRequest` [in]

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

A pointer to the object that handles the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationEventHandlerGroup](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationeventhandlergroup)