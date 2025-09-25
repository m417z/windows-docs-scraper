# MbbRequestCompleteWithInformation function

## Description

Client drivers call the **MbbRequestCompleteWithInformation** method to complete a specified request for receiving an MBIM response message from the device.

## Parameters

### `Request`

A handle to the framework request object passed in from the [*EvtMbbDeviceReceiveMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function.

### `NtStatus`

An NTSTATUS value that represents the completion status of the request.

### `Information`

The client driver must pass in the number of bytes it has written to the pre-allocated buffer.

## Remarks

This method must only be used to complete requests from the [*EvtMbbDeviceReceiveMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function.

To complete requests from the [*EvtMbbDeviceSendMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function, the client driver must call the [**MbbRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbrequestcomplete) method.

## See also