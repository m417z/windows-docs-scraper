## Description

A WiFiCx driver's *EvtWifiDeviceSendCommand* callback function retrieves and processes a command message sent by the WiFiCx framework.

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `SendRequest`

[_In_] A handle to a framework WIFIREQUEST object that represents a command message.

## Remarks

A WiFiCx client driver must register its *EvtWifiDeviceSendCommand* callback function by calling [**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize).

The WiFiCx framework invokes *EvtWifiDeviceSendCommand* to issue a command message to the client driver.

- To retrieve the message, the client driver calls [**WifiRequestGetInOutBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetinoutbuffer) to get the input/output buffer and buffer lengths. The driver also needs to call [**WifiRequestGetMessageId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetmessageid) to retrieve the message ID.

- To complete the request, the driver sends the M3 for the command asynchronously by calling [**WifiRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestcomplete).

- If this command is a set command and the original request did not contain a large enough buffer, the client should call [**WifiRequestSetBytesNeeded**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestsetbytesneeded) to set the required buffer size and then fail the request with status BUFFER\_OVERFLOW.

- If this command is a task command, the client driver needs to later send the associated M4 indication by calling [**WifiDeviceReceiveIndication**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicereceiveindication) and pass the indication buffer with a WDI header that contains the same message ID as contained in the M1.

For more information, see [Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages).

## See also

[Handling WiFiCx command messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#handling-wificx-command-messages)

[**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize)

[**WifiRequestGetInOutBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetinoutbuffer)

[**WifiRequestGetMessageId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestgetmessageid)

[**WifiRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifirequestcomplete)