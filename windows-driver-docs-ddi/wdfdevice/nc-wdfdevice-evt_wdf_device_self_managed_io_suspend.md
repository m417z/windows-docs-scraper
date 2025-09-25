# EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSelfManagedIoSuspend* event callback function suspends a device's self-managed I/O operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the operation is successful, the *EvtDeviceSelfManagedIoSuspend* callback function must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. If NT_SUCCESS(*status*) equals **FALSE**, the framework stops the device and removes its device objects.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush) and [EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) callback functions.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDeviceSelfManagedIoSuspend* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceSelfManagedIoSuspend* callback function, the framework calls it for one of the following reasons:

* The device is about to enter a low-power state.
* The device is being removed or was surprise-removed.
* The Plug and Play manager is about to redistribute the system's hardware resources among system's attached devices.

Because you do not know which of these events causes the framework to call your driver, you must assume that the device might return to its working (D0) state.

If the device is about to enter a low-power state, the framework calls the driver's *EvtDeviceSelfManagedIoSuspend* callback function before it calls the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function.

If the callback function returns a status value for which NT_SUCCESS(*status*) equals **FALSE**, and if the framework is attempting to lower the device's power, the framework stops the device and removes its device objects.

The *EvtDeviceSelfManagedIoSuspend* callback function must do whatever is needed to stop the device's self-managed I/O operations.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Using Self-Managed I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-self-managed-i-o).

## See also

[EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)

[EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush)

[EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)

[EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart)