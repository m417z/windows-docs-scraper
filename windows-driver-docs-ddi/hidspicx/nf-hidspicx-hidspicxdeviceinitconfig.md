## Description

The client driver must call **HidSpiCxDeviceInitConfig** in its [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback, before calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Parameters

### `DeviceInit`

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) object that the client received in its [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

## Return value

[**NTSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) indicating whether the class extension was able to successfully initialize the structure.

## Remarks

The class extension initializes private Plug-and-Play and power hooks for the device.

## See also

[EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)