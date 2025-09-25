## Description

WiFiCx drivers call the **WifiRequestSetBytesNeeded** function to set a larger buffer size for a command message.

## Parameters

### `Request`

[_In_] A handle to the framework request object passed in from the [*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function.

### `BytesNeeded`

[_In_] The number of bytes needed.

## Remarks

If WiFiCx sends a set command to the client driver's [*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function and the request doesn't contain a large enough buffer, the driver should call **WifiRequestSetBytesNeeded** to set the required buffer size and then fail the request with status BUFFER\_OVERFLOW.

## See also

[*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)