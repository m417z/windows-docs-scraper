# PoSetPowerState function (wdm.h)

## Description

The **PoSetPowerState** routine notifies the system of a change in the [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) for a device.

## Parameters

### `DeviceObject` [in]

A pointer to the target [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Type` [in]

Indicates a [POWER_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_state_type) value. Drivers must specify **DevicePowerState**.

### `State` [in]

Specifies the power state to be set. Drivers must specify a [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) value.

## Return value

On Windows 2000 and later versions of the operating system, **PoSetPowerState** returns the previous power state. On Windows 98/Me, **PoSetPowerState** returns the state passed in *State*.

## Remarks

**PoSetPowerState** notifies the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) of the new power state for a device. Each driver in a device stack (filter, function, and bus drivers) must call **PoSetPowerState** to inform the power manager of a change in the power state of its corresponding device object. For example:

* A driver calls this routine after receiving a device set-power request and before calling [PoStartNextPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartnextpowerirp). When handling a PnP [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request, the driver should call **PoSetPowerState** to notify the power manager that the device is in the D0 state.
* If the device is powering down, the driver must call **PoSetPowerState** before leaving the D0 state. In addition, the driver must be able to process client requests before **PoSetPowerState** returns.
* If the device is powering up, the driver must call **PoSetPowerState** after the device is successfully put into the D0 state.

For more information about powering a device up and down, see [Handling IRP_MN_SET_POWER for Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irp-mn-set-power-for-device-power-states).

Callers of **PoSetPowerState** must be running at IRQL <= APC_LEVEL except when setting state to D0. When setting state to D0, callers can be running at IRQL <= DISPATCH_LEVEL.

## See also

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[PoStartNextPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartnextpowerirp)