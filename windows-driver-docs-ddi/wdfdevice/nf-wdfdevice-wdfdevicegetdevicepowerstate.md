# WdfDeviceGetDevicePowerState function

## Description

[Applies to KMDF only]

>[!NOTE]
>This function is for Microsoft internal use only.

The **WdfDeviceGetDevicePowerState** method returns the current state of the framework's power state machine, for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetDevicePowerState** returns a [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator that identifies the current state of the framework's power state machine for the specified device.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the framework's state machines, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

The **WdfDeviceGetDevicePowerState** method returns a meaningful value only if it is called from within the following callback functions:

* [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)
* [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)
* [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)
* [EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled)
* [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)
* [EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled)
* [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)
* [EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend)
* [EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart)

#### Examples

The following code example obtains the current state of the framework's power state machine for a specified device.

```cpp
WDF_DEVICE_POWER_STATE state;

state = WdfDeviceGetDevicePowerState(Device);
```

## See also

[WdfDevStateNormalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevstatenormalize)

[WdfDeviceGetDevicePnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepnpstate)

[WdfDeviceGetDevicePowerPolicyState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerpolicystate)