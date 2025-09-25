# IUIAutomation5::AddNotificationEventHandler

## Description

Registers a method that handles notification events.

**Note** Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element associated with the event handler.

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

Type: **[IUIAutomationNotificationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationnotificationeventhandler)***

A pointer to the object that handles the notification event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomation5](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation5)

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)