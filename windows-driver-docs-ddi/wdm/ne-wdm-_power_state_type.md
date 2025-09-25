# _POWER_STATE_TYPE enumeration (wdm.h)

## Description

The **POWER_STATE_TYPE** enumeration type indicates that a power state value is a system power state or a device power state.

## Constants

### `SystemPowerState`

Indicates a [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state) value.

### `DevicePowerState`

Indicates a [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) value.

## Remarks

The **POWER_STATE_TYPE** enumeration type is used in conjunction with a value of type [POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_state) to indicate that the power state value is a system power state value or a device power state value. For an example, see [PoSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerstate).

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_state)

[PoSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerstate)

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)