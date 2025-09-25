# MbbDeviceSendDeviceServiceSessionDataComplete function

## Description

The **MbbDeviceSendServiceSessionDataComplete** method frees memory previously allocated by MBBCx for device service session data sent to the device.

## Parameters

### `Data`

A WDFMEMORY object that contains data passed to the device.

### `NtStatus`

An NTSTATUS value indicating the status of the send operation.

## Remarks

Client drivers must call this method from within the [*EvtMbbDeviceSendServiceSessionData*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_device_service_session_data) callback function after they have sent the DSS data to the device.

## See also