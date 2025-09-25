# EVT_WDF_DEVICE_D0_EXIT callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceD0Exit* event callback function performs operations that are needed when the driver's device leaves the D0 power state.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `TargetState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)-typed enumerator that identifies the device power state that the device is about to enter.

## Return value

If the *EvtDeviceD0Exit* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

To register an *EvtDeviceD0Exit* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceD0Exit* callback function, the framework calls the function each time one of the driver's devices leaves its working (D0) state. A device leaves the D0 state when one of the following occurs:

* The system and all of its devices are about to leave their working states and enter a low-power state.
* The device is about to enter a low-power state because it is idle, if the device supports low-power idle.
* The Plug and Play manager is attempting to redistribute the system's hardware resources.
* A user has indicated, typically by means of an application's user interface, that he or she wants to remove the device.

The framework also calls the *EvtDeviceD0Exit* callback function after a device has been removed unexpectedly (surprise-removed).

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

Unless the device has been surprise-removed, the framework calls this callback function immediately after it disables the device's interrupts, but before the device's power is reduced from D0. The *TargetState* parameter identifies the device power state that the device is about to enter.

The *EvtDeviceD0Exit* callback function must perform any operations that are necessary before the device enters the specified low-power state, such as saving any information that the driver will need later to restore the device to its D0 power state.

If the *TargetState* parameter is **WdfPowerDevicePrepareForHibernation**, the driver must not shut off the device, because the system will use the device when saving its hibernation file.

If *TargetState* is **WdfPowerDeviceD3Final**, you should assume that the system is being turned off, the device is about to be removed, or a [resource rebalance](https://learn.microsoft.com/windows-hardware/drivers/wdf/the-pnp-manager-redistributes-system-resources) is in progress. If your driver must save information, it should write it to disk or some other permanent storage medium. However, it is incorrect to check **WdfPowerDeviceD3Final** and then do cleanup work for device removal. For example, if a device that has entered Dx power state because of idling out is then later surprise removed, its *EvtDeviceD0Exit* won't be called again. The correct place to do this work would be in [*EvtDeviceReleaseHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) instead.

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

## See also

[EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)