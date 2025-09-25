# _WDF_DEVICE_POWER_NOTIFICATION_DATA structure

## Description

[Applies to KMDF only]

>[!NOTE]
>This structure is for Microsoft internal use only.

The WDF_DEVICE_POWER_NOTIFICATION_DATA structure describes a state change within a device's power state machine.

## Members

### `Type`

A [WDF_STATE_NOTIFICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_state_notification_type)-typed enumerator that identifies the type of state change that is being reported.

### `Data`

### `Data.EnterState`

### `Data.EnterState.CurrentState`

If **Type** is **StateNotificationEnterState**, this [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator identifies the state machine's current state.

### `Data.EnterState.NewState`

If **Type** is **StateNotificationEnterState**, this [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator identifies the state machine's next state.

### `Data.PostProcessState`

### `Data.PostProcessState.CurrentState`

If **Type** is **StateNotificationEnterState**, this [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator identifies the state machine's current state.

### `Data.LeaveState`

### `Data.LeaveState.CurrentState`

If **Type** is **StateNotificationEnterState**, this [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator identifies the state machine's current state.

### `Data.LeaveState.NewState`

If **Type** is **StateNotificationEnterState**, this [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator identifies the state machine's next state.

## Remarks

The **WDF_DEVICE_POWER_NOTIFICATION_DATA** structure is an input argument to a driver's [EvtDevicePowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_power_state_change_notification) callback function.

## See also

[WdfDeviceInitRegisterPowerStateChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitregisterpowerstatechangecallback)