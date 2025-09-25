# IUIAutomation6::CreateEventHandlerGroup

## Description

Registers one or more event listeners in a single method call.

> [!Important]
> Microsoft UI Automation clients should use the handler group methods to register event listeners instead of individual event registration methods defined in the various [IUIAutomation interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomation).

## Parameters

### `handlerGroup` [out]

A collection of UI Automation event listeners.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## See also

[AddEventHandlerGroup](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-addeventhandlergroup), [IUIAutomation6 interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomation6), [IUIAutomation6::RemoveEventHandlerGroup](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-removeeventhandlergroup)