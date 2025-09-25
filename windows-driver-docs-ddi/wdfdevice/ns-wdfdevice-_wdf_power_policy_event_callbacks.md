# _WDF_POWER_POLICY_EVENT_CALLBACKS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_POLICY_EVENT_CALLBACKS** structure contains pointers to a driver's power policy event callback functions.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceArmWakeFromS0`

A pointer to the driver's [EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0) event callback function, or **NULL**.

### `EvtDeviceDisarmWakeFromS0`

A pointer to the driver's [EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0) event callback function, or **NULL**.

### `EvtDeviceWakeFromS0Triggered`

A pointer to the driver's [EvtDeviceWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_s0_triggered) event callback function, or **NULL**.

### `EvtDeviceArmWakeFromSx`

A pointer to the driver's [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx) event callback function, or **NULL**.

### `EvtDeviceDisarmWakeFromSx`

A pointer to the driver's [EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx) event callback function, or **NULL**.

### `EvtDeviceWakeFromSxTriggered`

A pointer to the driver's [EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered) event callback function, or **NULL**.

### `EvtDeviceArmWakeFromSxWithReason`

A pointer to the driver's [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) event callback function, or **NULL**.

## Remarks

The **WDF_POWER_POLICY_EVENT_CALLBACKS** structure is used as input to the [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks) method.

Your driver should initialize its **WDF_POWER_POLICY_EVENT_CALLBACKS** structure by calling [WDF_POWER_POLICY_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_policy_event_callbacks_init).

## See also

[WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks)