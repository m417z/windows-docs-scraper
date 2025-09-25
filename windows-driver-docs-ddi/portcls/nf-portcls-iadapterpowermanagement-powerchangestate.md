# IAdapterPowerManagement::PowerChangeState

## Description

The `PowerChangeState` method requests that the device change to a new power state.

## Parameters

### `NewState` [in]

Specifies the new power state being requested for the device. This parameter is a union of type POWER_STATE. The new power state (*NewState*.**DeviceState**) can be one of the [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration values shown in the following table.

| Power State | Meaning |
| --- | --- |
| PowerDeviceD0 | Full power state (D0). This code may be a function of the current power state. Save the new state. This local value is used to determine when to cache property accesses and when to permit the driver from accessing the hardware. |
| PowerDeviceD1 | The sleep state having the lowest latency with respect to the latency time required to return to D0 |
| PowerDeviceD2 | A medium latency sleep state. In this state, the device driver cannot assume that it can touch the hardware, so any accesses need to be cached and the hardware restored upon entering D0. |
| PowerDeviceD3 | A full hibernation state and is the longest latency sleep state. The driver cannot access the hardware in this state and must cache any hardware accesses and restore the hardware upon returning to D0 or D1 |

## Remarks

PortCls calls the `PowerChangeState` method in response to an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) power IRP. This call must not fail. PortCls and the system use the `PowerChangeState` call to place the device in the desired power state. When the system attempts to suspend or resume an active audio stream, the driver must be capable of saving or restoring its device context appropriately.

To assist the driver, PortCls will pause any active audio streams prior to calling this method to place the device in a sleep state. After calling this method, PortCls will unpause active audio streams, to wake the device up. Miniports can opt for additional notification by utilizing the [IPowerNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-ipowernotify) interface.

The miniport driver must perform the requested change to the device's power state before it returns from the `PowerChangeState` call. If the miniport driver needs to save or restore any device state before a power-state change, the miniport driver should support the **IPowerNotify** interface, which allows it to receive advance warning of any such change. Before returning from a successful `PowerChangeState` call, the miniport driver should cache the new power state.

While the miniport driver is in one of the sleep states (any state other than PowerDeviceD0), it must avoid writing to the hardware. The miniport driver must cache any hardware accesses that need to be deferred until the device powers up again. If the power state is changing from one of the sleep states to PowerDeviceD0, the miniport driver should perform any deferred hardware accesses after it has powered up the device. If the power state is changing from PowerDeviceD0 to a sleep state, the miniport driver can perform any necessary hardware accesses during the `PowerChangeState` call before it powers down the device.

While powered down, a miniport driver is never asked to create a miniport driver object or stream object. PortCls always places the device in the PowerDeviceD0 state before calling the miniport driver's **NewStream** method.

The code for this method must reside in paged memory.

## See also

[IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement)

[IPowerNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-ipowernotify)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)