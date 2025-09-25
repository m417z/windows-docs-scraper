# _POWER_STATE structure (ntpoapi.h)

## Description

The **POWER_STATE** union specifies a [system power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-states) value or a device power state value.

## Members

### `SystemState`

A system power state value of type [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state).

### `DeviceState`

A device power state value of type [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state).

## Remarks

The **POWER_STATE** union is used in conjunction with the [POWER_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_state_type) enumeration type to specify a system power state value or a device power state value. This union is also used in cases where the power state type is implicitly determined by the context in which it is used. For example, see [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp) and [PoSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerstate).

For more information about power management, see [Introduction to Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-power-management).

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[POWER_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_state_type)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)

[PoSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerstate)

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)