# IUIEventLogger::OnUIEvent

## Description

Receives notifications that a ribbon event has occurred.

## Parameters

### `pEventParams` [in]

The parameters associated with the event. This value varies according to the event type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIEventLogger](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuieventlogger)

[UI_EVENTLOCATION](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventlocation)

[UI_EVENTPARAMS](https://learn.microsoft.com/windows/desktop/api/uiribbon/ns-uiribbon-ui_eventparams)

[UI_EVENTTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventtype)