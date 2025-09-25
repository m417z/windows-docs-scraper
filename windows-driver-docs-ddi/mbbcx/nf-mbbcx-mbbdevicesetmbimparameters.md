# MbbDeviceSetMbimParameters function

## Description

The client driver calls the **MbbDeviceSetMbimParameters** method to report its MBIM-specification related parameters.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `MbimParameters`

A pointer to a client driver-allocated and initialized [**MBB_DEVICE_MBIM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_mbim_parameters) structure.

## Remarks

The client driver typically calls this method from within [*EVT_DEVICE_PREPARE_HARDWARE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

For more information, see [Initialize the device](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#initialize-the-device).

## See also