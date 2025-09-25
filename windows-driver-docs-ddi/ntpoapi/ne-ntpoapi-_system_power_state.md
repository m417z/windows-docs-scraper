# _SYSTEM_POWER_STATE enumeration (ntpoapi.h)

## Description

The **SYSTEM_POWER_STATE** enumeration type is used to indicate a [system power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-states).

## Constants

### `PowerSystemUnspecified`

Indicates an unspecified system power state.

### `PowerSystemWorking`

Indicates maximum system power, which corresponds to [system working state S0](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0).

### `PowerSystemSleeping1`

Indicates a [system sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states) less than **PowerSystemWorking** and greater than **PowerSystemSleeping2**, which corresponds to system power state S1.

### `PowerSystemSleeping2`

Indicates a system sleeping state less than **PowerSystemSleeping1** and greater than **PowerSystemSleeping3**, which corresponds to system power state S2.

### `PowerSystemSleeping3`

Indicates a system sleeping state less than **PowerSystemSleeping2** and greater than **PowerSystemHibernate**, which corresponds to system power state S3.

### `PowerSystemHibernate`

Indicates the lowest-powered sleeping state, which corresponds to system power state S4.

### `PowerSystemShutdown`

Indicates the system is turned off, which corresponds to [system shutdown state S5](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-shutdown-state-s5).

### `PowerSystemMaximum`

The number of system power state values for this enumeration type that represents actual power states. This value is the number of elements in the **DeviceState** member of the [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure for a device. The other system power state values are less than this value.

## Remarks

A power state indicates the level of power consumption—and thus the extent of computing activity—by the system or by a single device. The power manager sets the power state of the system as a whole, where the system power state is indicated by one of the values of the **SYSTEM_POWER_STATE** enumeration type. Device drivers set the power state of their individual devices, where the device power state is indicated by one of the values of the [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration type.

For more information about system power states, see [Handling System Power State Requests](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-system-power-state-requests) and for more information about device power states, see [Managing Power for Individual Devices](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-power-for-individual-devices).

For more information about power management in general, see [Introduction to Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-power-management).

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)