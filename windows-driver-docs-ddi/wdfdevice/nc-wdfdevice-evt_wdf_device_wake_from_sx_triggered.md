# EVT_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceWakeFromSxTriggered* event callback function informs the driver that its device, which had previously entered a low-power device state because system power was reduced, might have triggered a wake signal.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceWakeFromSxTriggered* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks).

If the driver has registered this callback, the framework calls it after calling the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function and before calling the driver's [EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx) callback function.

System hardware (BIOSes, motherboards, bus adapters) can sometimes drop a wake signal before the bus driver detects it, even though the signal wakes up the system. In such cases, the driver's *EvtDeviceWakeFromSxTriggered* callback function will not be called even though the driver's device triggered a wake signal.

Some buses combine wake signals from several children. If your device is connected to one of these buses, the callback function might have to determine if the current device triggered the wake-up signal. If your device provides a hardware latch that saves the device's triggered state, it is best to check that state in the driver's [EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx) callback function, because that callback is always called after the device wakes up, even if the wake signal was dropped.

For more information about this callback function, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

## See also

[EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)

[EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx)

[EvtDeviceWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_s0_triggered)