# IUIAutomation2::put_TransactionTimeout

## Description

Specifies the length of time that UI Automation will wait for a provider to respond to a client request for information about an automation element.

This property is read/write.

## Parameters

### `timeout` [in]

Type: **DWORD**

The duration of the time-out period, in milliseconds.

## Remarks

The default transaction timeout value is 20 seconds. Because some operations require the provider to process hundreds of elements, the provider might need a significant amount of time to return information to the client.

## See also

[IUIAutomation2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation2)