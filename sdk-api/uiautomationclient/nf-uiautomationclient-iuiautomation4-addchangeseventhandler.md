# IUIAutomation4::AddChangesEventHandler

## Description

Registers a method that handles change events.

**Note** Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element associated with the event handler.

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `changeTypes` [in]

Type: **int***

A pointer to a list of integers that indicate the change types the event represents.

### `changesCount` [in]

Type: **int**

The number of changes that occurred in this event.

### `pCacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

Type: **[IUIAutomationChangesEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationchangeseventhandler)***

A pointer to the object that handles the changes event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A Microsoft UI Automation client should not use multiple threads to add or remove event handlers. Unexpected behavior can result if one event handler is being added or removed while another is being added or removed in the same client process.

## See also

[IUIAutomation4](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation4)

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)