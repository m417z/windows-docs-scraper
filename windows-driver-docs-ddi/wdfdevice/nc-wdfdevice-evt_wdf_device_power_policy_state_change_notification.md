# EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION callback function

## Description

[Applies to KMDF only]

>[!NOTE]
>This callback function is for Microsoft-internal use only.

A driver's *EvtDevicePowerPolicyStateChange* event callback function informs the driver that a device's power policy state machine is moving from one state to another.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `NotificationData` [in]

A pointer to a framework-supplied [WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_notification_data) structure that identifies the state machine's old and new states.

## Remarks

To register an *EvtDevicePowerPolicyStateChange* callback function, a driver must call [WdfDeviceInitRegisterPowerPolicyStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpowerpolicystatechangecallback).

For more information, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

If the *EvtDevicePowerPolicyStateChange* callback function calls [WdfDeviceStopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle) with the *WaitForD0* parameter set to **TRUE**, the framework's power policy state machine will become deadlocked.

## See also

[EvtDevicePnpStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_pnp_state_change_notification)

[EvtDevicePowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_power_state_change_notification)