## Description

WiFiCx drivers call the **WifiDeviceReceiveIndication** function to send a status indication to the WiFiCx framework.

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `MessageId`

[_In_] When indicating the completion of a task command, set this value to the command message ID that the driver obtained from a previous call to [**WifiRequestGetMessageId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetmessageid).

### `Data`

[_In_] A driver-allocated WDFMEMORY object containing the data to pass to WiFiCx.

## Remarks

For more information, see [Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages).

## See also

[**WifiRequestGetMessageId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetmessageid)

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)