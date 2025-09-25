# EVT_WDF_DEVICE_D0_ENTRY callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceD0Entry* event callback function performs operations that are needed when the driver's device enters the D0 power state.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PreviousState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)-typed enumerator that identifies the previous device power state.

## Return value

If the *EvtDeviceD0Entry* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

The framework does not call the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function after the *EvtDeviceD0Entry* callback function returns a status value for which NT_SUCCESS(status) equals **FALSE**.

## Remarks

To register an *EvtDeviceD0Entry* callback function for a device, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDeviceD0Entry* callback function for a device, the framework calls the function each time the device enters its working (D0) state. A device will enter the D0 state when one of the following occurs:

* A device is enumerated (because the device was plugged in or the system was rebooted).
* The system and all of its devices return to their working states from a low-power state.
* The device returns to its working state after it entered a low-power state because it was idle (if the device supports low-power idle).
* The Plug and Play manager has redistributed the system's hardware resources among the system's devices.

The framework calls the *EvtDeviceD0Entry* callback function immediately after the device enters its working (D0) state and is available to the driver, but before the device's interrupts have been enabled. The *PreviousState* parameter identifies the device power state that the device was in before it entered the D0 state. When the framework first calls *EvtDeviceD0Entry*, it provides a *PreviousState* value of **WdfPowerDeviceD3Final**.

The callback function must perform any operations that are needed to make the device fully operational, such as loading firmware or enabling device capabilities that are disabled when the device is in a low-power state.

If the *EvtDeviceD0Entry* callback function returns a status value for which NT_SUCCESS(*status*) equals **FALSE**, the framework does the following:

* If the device is starting for the first time, the framework begins an [orderly removal](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-user-unplugs-a-device) sequence for the device.
* If the device is returning from a low-power state to its working state, the framework begins a [surprise removal](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-user-unplugs-a-device) sequence for the device.

The framework does not call the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function in either of these situations.

For more information about when the framework calls the *EvtDeviceD0Entry* callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

The *EvtDeviceD0Entry* callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)