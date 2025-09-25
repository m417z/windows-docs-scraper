## Description

WiFiCx drivers call the **WifiRequestComplete** function to complete a request to send a command message to the device.

## Parameters

### `Request`

[_In_] A handle to the framework request object passed in from the [*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function.

### `NtStatus`

[_In_] An NTSTATUS value that represents the completion status of the request.

### `BytesWritten`

[_In_] The number of bytes written.

## Remarks

WiFiCx drivers call **WifiRequestComplete** to complete requests from the [*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function.

For more information see [Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages).

## See also

[*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)