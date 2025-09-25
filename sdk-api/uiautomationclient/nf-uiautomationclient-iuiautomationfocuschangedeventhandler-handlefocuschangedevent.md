# IUIAutomationFocusChangedEventHandler::HandleFocusChangedEvent

## Description

Handles the event raised when the keyboard focus moves to a different UI Automation element.

## Parameters

### `sender` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element that has received the focus.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that were subscribed to by using [AddFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addfocuschangedeventhandler)

The UI Automation element represented by *sender* might not have any cached properties or control patterns, depending on whether the application subscribed to this event while a cache request was active.

Adjusting an event handler from within this method is not supported.

## See also

[IUIAutomationFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationfocuschangedeventhandler)