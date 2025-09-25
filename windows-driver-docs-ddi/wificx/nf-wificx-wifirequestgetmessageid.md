## Description

The **WifiRequestGetMessageId** function returns the ID of a WiFiCx command message.

## Parameters

### `Request`

[_In_] A handle to the framework object which represents a command message from the WiFiCx framework.

## Return value

Returns the message ID of the command.

## Remarks

WiFiCx drivers typically call **WifiRequestGetMessageId** in their [*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function to get the ID of the command message sent by the WiFiCx framework.

For more information, see [Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages).

## See also

[*EvtWifiDeviceSendCommand*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)