# EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSelfManagedIoInit* event callback function initializes and starts the device's self-managed I/O operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the *EvtDeviceSelfManagedIoInit* callback function encounters no errors, it must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. If NT_SUCCESS(*status*) equals **FALSE**, the framework does not start the device.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush) and [EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) callback functions.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDeviceSelfManagedIoInit* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceSelfManagedIoInit* callback function, the framework calls it once for each device, after the framework has called the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function for the first time. The framework does not call the *EvtDeviceSelfManagedIoInit* callback function again for that device, unless the device is removed and reconnected, or the drivers are reloaded.

The *EvtDeviceSelfManagedIoInit* callback function must initialize and start the self-managed I/O operations that the driver will handle for the device.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Using Self-Managed I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-self-managed-i-o).

## See also

[EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)

[EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush)

[EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart)

[EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend)