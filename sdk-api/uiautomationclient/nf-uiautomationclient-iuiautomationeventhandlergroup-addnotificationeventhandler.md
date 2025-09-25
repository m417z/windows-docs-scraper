# IUIAutomationEventHandlerGroup::AddNotificationEventHandler

## Description

Registers a method that handles notification events.

**Important** Microsoft UI Automation clients should use the handler group methods to register event listeners instead of individual event registration methods defined in the various [IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation) namespaces.

## Parameters

### `scope` [in]

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `cacheRequest` [in]

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

A pointer to the object that handles the notification event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## See also

[IUIAutomationEventHandlerGroup](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationeventhandlergroup)