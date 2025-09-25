# EVT_WDF_DEVICE_SELF_MANAGED_IO_RESTART callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSelfManagedIoRestart* event callback function restarts a device's self-managed I/O operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the *EvtDeviceSelfManagedIoRestart* callback function encounters no errors, it must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. If NT_SUCCESS(*status*) equals **FALSE**, the framework stops the device and unloads the device's drivers.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush) and [EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) callback functions.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDeviceSelfManagedIoRestart* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceSelfManagedIoRestart* callback function, the framework calls it each time that the device returns from a low-power state to its working (D0) state. The framework calls the *EvtDeviceSelfManagedIoRestart* callback function only after calling the driver's [EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend) callback function.

The driver's *EvtDeviceSelfManagedIoRestart* callback function must do whatever is needed to resume the device's self-managed I/O operations.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Using Self-Managed I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-self-managed-i-o).

The *EvtDeviceSelfManagedIoRestart* callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)

[EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush)

[EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)

[EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend)