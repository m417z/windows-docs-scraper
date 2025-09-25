# EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION callback function

## Description

[Applies to KMDF only]

>[!NOTE]
>This callback function is for Microsoft-internal use only.

A driver's *EvtDevicePnpStateChange* event callback function informs the driver that a device's Plug and Play (PnP) state machine is moving from one state to another.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `NotificationData` [in]

A pointer to a framework-supplied [WDF_DEVICE_PNP_NOTIFICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_notification_data) structure that identifies the state machine's old and new states.

## Remarks

To register an *EvtDevicePnpStateChange* callback function, a driver must call [WdfDeviceInitRegisterPnpStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpnpstatechangecallback).

For more information about the framework's PnP state machine, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

## See also

[EvtDevicePowerPolicyStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_power_policy_state_change_notification)

[EvtDevicePowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_power_state_change_notification)