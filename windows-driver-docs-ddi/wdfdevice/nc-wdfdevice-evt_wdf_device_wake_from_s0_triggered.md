# EVT_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceWakeFromS0Triggered* event callback function informs the driver that its device, which had previously entered a low-power device state while the system power state remained at S0, might have triggered a wake signal.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceWakeFromS0Triggered* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks).

If the driver has registered this callback, the framework calls it after calling the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function and before calling the driver's [EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0) callback function.

System hardware (BIOSes, motherboards, bus adapters) can sometimes drop a wake signal before the bus driver detects it, even though the signal wakes up the system. In such cases, the driver's *EvtDeviceWakeFromS0Triggered* callback function will not be called even though the driver's device triggered a wake signal.

Some buses combine wake signals from several children. If your device is connected to one of these buses, the callback function might have to determine if the current device triggered the wake-up signal. If your device provides a hardware latch that saves the device's triggered state, it is best to check that state in the driver's [EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0) callback function, because that callback is always called after the device wakes up, even if the wake signal was dropped.

For more information about this callback function, see [Supporting Idle Power-Down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down).

## See also

[EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)

[EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0)

[EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered)