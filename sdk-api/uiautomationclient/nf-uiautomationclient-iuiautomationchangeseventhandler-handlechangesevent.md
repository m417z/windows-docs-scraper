# IUIAutomationChangesEventHandler::HandleChangesEvent

## Description

Handles one or more Microsoft UI Automation change events.

## Parameters

### `sender` [in]

A pointer to the element that raised the event.

### `uiaChanges` [in]

A collection of pointers to [UiaChangeInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiachangeinfo) structures.

### `changesCount` [in]

The number of changes that occurred. This is the number of [UiaChangeInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiachangeinfo) structures pointed to by the *uiaChanges* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that it has subscribed to by calling [AddChangesEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation4-addchangeseventhandler).

## See also

[IUIAutomationChangesEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationchangeseventhandler)