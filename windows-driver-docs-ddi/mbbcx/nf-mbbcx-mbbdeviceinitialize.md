# MbbDeviceInitialize function

## Description

The **MbbDeviceInitialize** method registers the client driver's MBB-specific callback functions.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config`

A pointer to a client driver-allocated and initialized [**MBB_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_config) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate NTSTATUS error code.

This method might return failure in low resource situations.

## Remarks

The client driver must call this method after it calls [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) from within [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add).

For more information, see [Initialize the device](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#initialize-the-device).

## See also