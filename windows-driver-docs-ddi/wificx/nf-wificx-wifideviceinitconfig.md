## Description

The **WifiDeviceInitConfig** function initializes WiFiCx device initialization operations when the Plug and Play (PnP) manager reports the existence of a device.

## Parameters

### `DeviceInit`

[_Inout_] A pointer to a [**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) object that the client driver received in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

In its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, a WifiCx client driver calls **WifiDeviceInitConfig** after calling [**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig) but before calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

The driver must reference the same [**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) object passed in by the framework.

## See also

[**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)