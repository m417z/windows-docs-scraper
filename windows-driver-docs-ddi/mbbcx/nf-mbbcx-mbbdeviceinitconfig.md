# MbbDeviceInitConfig function

## Description

The **MBBDeviceInitConfig** method initializes MBBCx device initialization operations when the Plug and Play (PnP) manager reports the existence of a device.

## Parameters

### `DeviceInit`

A pointer to a **WDFDEVICE_INIT** object that the client received in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate NTSTATUS error code.

## Remarks

The client driver calls this method in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback after it calls [**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig), but before it calls [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information, see [Initialize the device](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#initialize-the-device).

## See also

[**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig)

[*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[Initialize the device](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#initialize-the-device)