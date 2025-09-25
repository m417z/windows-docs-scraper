# IUIAutomation2::get_ConnectionTimeout

## Description

Specifies the length of time that UI Automation will wait for a provider to respond to a client request for an automation element.

This property is read/write.

## Parameters

### `timeout` [out]

Type: **DWORD**

The duration of the time-out period, in milliseconds.

## Remarks

The default connection timeout value is two seconds. A responsive UI Automation provider can typically return an automation element to a client in a short length of time.

## See also

[IUIAutomation2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation2)