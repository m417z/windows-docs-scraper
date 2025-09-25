# _DEVICE_POWER_STATE enumeration (wdm.h)

## Description

The **DEVICE_POWER_STATE** enumeration type indicates a [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states).

## Constants

### `PowerDeviceUnspecified`

Indicates an unspecified device power state.

### `PowerDeviceD0`

Indicates a maximum device power state, which corresponds to [device working state D0](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-working-state-d0).

### `PowerDeviceD1`

Indicates a [device sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states) less than **PowerDeviceD0** and greater than **PowerDeviceD2**, which corresponds to device power state D1.

### `PowerDeviceD2`

Indicates a device sleeping state less than **PowerDeviceD1** and greater than **PowerDeviceD3**, which corresponds to device power state D2.

### `PowerDeviceD3`

Indicates the lowest-powered device sleeping state, which corresponds to device power state D3.

### `PowerDeviceMaximum`

The number of device power state values for this enumeration type that represent actual power states. The value of the other device power states is less than this value.

## Remarks

A power state indicates the level of power consumption—and thus the extent of computing activity—by the system or by a single device. The power manager sets the power state of the system as a whole, where the system power state is indicated by one of the values of the [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state) enumeration type. Device drivers set the power state of their individual devices, where the device power state is indicated by one of the values of the **DEVICE_POWER_STATE** enumeration type.

For more information about system power states, see [Handling System Power State Requests](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-system-power-state-requests). For more information about device power states, see [Managing Power for Individual Devices](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-power-for-individual-devices). For more information about power management in general, see [Introduction to Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-power-management).

## See also

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)