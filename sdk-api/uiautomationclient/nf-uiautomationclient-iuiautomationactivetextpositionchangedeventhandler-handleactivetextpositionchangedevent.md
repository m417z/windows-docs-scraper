# IUIAutomationActiveTextPositionChangedEventHandler::HandleActiveTextPositionChangedEvent

## Description

Handles a Microsoft UI Automation active text position change event.

**Note** This method is implemented by the application to handle events that it has subscribed to by calling [AddActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-addactivetextpositionchangedeventhandler).

## Parameters

### `sender` [in]

A pointer to the UI Automation element that raised the event.

### `range`

A span of continuous text in a container that supports the [IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## See also

[IUIAutomationActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationactivetextpositionchangedeventhandler)