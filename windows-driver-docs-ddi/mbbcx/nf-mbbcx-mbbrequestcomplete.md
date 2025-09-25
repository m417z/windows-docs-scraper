# MbbRequestComplete function

## Description

Client drivers call the **MbbRequestComplete** method to complete a specified request for sending an MBIM control message to the device.

## Parameters

### `Request`

A handle to the framework request object passed in from the [*EvtMbbDeviceSendMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function.

### `NtStatus`

An NTSTATUS value that represents the completion status of the request.

## Remarks

This method must only be used to complete requests from the [*EvtMbbDeviceSendMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function.

To complete the request from the [*EvtMbbDeviceReceiveMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function, the client driver must call the [**MbbRequestCompleteWithInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbrequestcompletewithinformation) method.

## See also