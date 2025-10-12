# EVT_WDF_DEVICE_DISARM_WAKE_FROM_S0 callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceDisarmWakeFromS0* event callback function disarms (that is, disables) a device's ability to trigger a wake signal while in a low-power device state, if the system remains in the [system working state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0) (S0).

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceDisarmWakeFromS0* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks). The driver must also set **IdleCanWakeFromS0** in the **IdleCaps** member of its [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

If the driver has registered an *EvtDeviceDisarmWakeFromS0* callback function, the framework calls it after the bus driver determines that an event has awakened the device, and after the bus driver subsequently completes the [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp). Before calling the driver's *EvtDeviceDisarmWakeFromS0* callback function, the framework calls the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry), [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable), and [EvtDeviceWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_s0_triggered) callback functions.

The *EvtDeviceDisarmWakeFromS0* callback function must perform any hardware operations that are needed to disable the device's ability to trigger a wake signal after the power has been lowered.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about this callback function, see [Supporting Idle Power-Down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down).

The *EvtDeviceDisarmWakeFromS0* callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)

[EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx)