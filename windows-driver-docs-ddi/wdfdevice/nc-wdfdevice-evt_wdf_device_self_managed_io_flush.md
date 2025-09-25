# EVT_WDF_DEVICE_SELF_MANAGED_IO_FLUSH callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSelfManagedIoFlush* event callback function handles flush activity for the device's self-managed I/O operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceSelfManagedIoFlush* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceSelfManagedIoFlush* callback function, the framework calls it after the device has been removed. The driver should flush (that is, remove) I/O requests that are associated with the device's self-managed I/O operations.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Using Self-Managed I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-self-managed-i-o).

## See also

[EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)

[EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)

[EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart)

[EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend)