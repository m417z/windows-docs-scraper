## Description

WiFiCx drivers call the **WifiRequestGetInOutBuffer** function to get the input/output buffer for a command message.

## Parameters

### `Request`

[_In_] A handle to the framework object which represents a command message from the WiFiCx framework.

### `InputBufferLength`

[_Out_opt_] A pointer to the location that receives the length, in bytes, of the command message input buffer.

### `OutBufferLength`

[_Out_opt_] A pointer to the location that receives the length, in bytes, of the command message output buffer.

## Return value

Returns a pointer to the memory location where the command message is stored.

## Remarks

For more information, see [Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages).

## See also

[*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)