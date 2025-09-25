# EVT_WDF_DEVICE_DISARM_WAKE_FROM_SX callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceDisarmWakeFromSx* event callback function disarms (that is, disables) a device's ability to trigger a wake signal while the device and system are in low-power states.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceDisarmWakeFromSx* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks).

If the driver has registered this callback function, the framework calls it after the framework has determined that system power is being restored, and after the bus driver completes the [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp). Before calling the driver's *EvtDeviceDisarmWakeFromSx* callback function, the framework calls the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry), [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable), and [EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered) callback functions.

The *EvtDeviceDisarmWakeFromSx* callback function must perform any hardware operations that are needed to disable the device's ability to trigger a wake signal after the power has been lowered.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about this callback function, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

The *EvtDeviceDisarmWakeFromSx* callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)

[EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0)

[EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered)