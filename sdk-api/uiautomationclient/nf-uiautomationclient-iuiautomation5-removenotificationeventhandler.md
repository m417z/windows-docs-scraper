# IUIAutomation5::RemoveNotificationEventHandler

## Description

Removes a notification event handler.

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the UI Automation element from which to remove the handler.

### `handler` [in]

Type: **[IUIAutomationNotificationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationnotificationeventhandler)***

A pointer to the interface that was passed to [AddNotificationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation5-addnotificationeventhandler).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomation5](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation5)

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)