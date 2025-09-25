# _WDF_STATE_NOTIFICATION_TYPE enumeration

## Description

[Applies to KMDF only]

>[!NOTE]
>This enumeration is for Microsoft internal use only.

The **WDF_STATE_NOTIFICATION_TYPE** enumeration identifies the type of Plug and Play, power, or power policy notification that a framework-based driver will receive.

## Constants

### `StateNotificationInvalid:0x0000`

For internal use only.

### `StateNotificationEnterState:0x0001`

The driver is notified immediately before a device's Plug and Play, power, or power policy state machine enters a specified state.

### `StateNotificationPostProcessState:0x0002`

The driver is notified immediately after a device's Plug and Play, power, or power policy state machine enters a specified state.

### `StateNotificationLeaveState:0x0004`

The driver is notified immediately before a device's Plug and Play, power, or power policy state machine leaves a specified state.

### `StateNotificationAllStates:StateNotificationEnterState` | StateNotificationPostProcessState | StateNotificationLeaveState

The driver receives enter-state, postprocess-state, and leave-state notifications.

## Remarks

When the framework's state machine for a driver's device changes from state *a* to state *b*, the framework notifies the driver (if the driver registered an appropriate event callback function), in the following sequence:

1. Calls state *a*'s leave-state notification callback function.
2. Calls state *b*'s enter-state notification callback function.
3. Changes the device's state from *a* to *b*.
4. Calls state *b*'s postprocess-state notification callback function.

To register for notification of a change in state, the driver can call the following methods:

* [WdfDeviceInitRegisterPnpStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpnpstatechangecallback)
* [WdfDeviceInitRegisterPowerStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpowerstatechangecallback)
* [WdfDeviceInitRegisterPowerPolicyStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpowerpolicystatechangecallback)

## See also

[WDF_DEVICE_PNP_NOTIFICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_notification_data)

[WDF_DEVICE_POWER_NOTIFICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_notification_data)

[WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_notification_data)