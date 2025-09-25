# EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSelfManagedIoCleanup* event callback function handles deallocation activity for the device's self-managed I/O operations, after a device has been removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceSelfManagedIoCleanup* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceSelfManagedIoCleanup* callback function, the framework calls it after the specified device has been removed from the system. For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

The framework calls the driver's *EvtDeviceSelfManagedIoCleanup* callback function after it has called the driver's [EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend) callback function. The *EvtDeviceSelfManagedIoCleanup* callback function must release any system resources that the driver allocated and associated with the device's self-managed I/O operations.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Using Self-Managed I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-self-managed-i-o).

## See also

[EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush)

[EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)

[EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart)

[EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend)