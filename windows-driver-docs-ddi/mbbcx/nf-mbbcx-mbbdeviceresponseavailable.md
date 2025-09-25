# MbbDeviceResponseAvailable function

## Description

A client driver calls the **MbbDeviceResponseAvailable** method when there is an MBIM control message ready from the device, as the response to a previous MBIM control message sent to the device from the MBBCx framework.

It can also call this method to notify the MBBCx framework of an unsolicited device event.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Remarks

For more information, see [Handling MBIM control messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#handling-mbim-control-messages).

## See also