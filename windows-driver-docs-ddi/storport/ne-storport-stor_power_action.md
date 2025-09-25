## Description

The **STOR_POWER_ACTION** enumeration identifies the system power actions that can occur on a computer.

## Constants

### `StorPowerActionNone`

No power action is taking place.

### `StorPowerActionReserved`

Reserved for system use.

### `StorPowerActionSleep`

The computer is entering a [system sleeping (S1, S2, or S3) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states).

### `StorPowerActionHibernate`

The computer is entering its [hibernation (S4) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states).

### `StorPowerActionShutdown`

The computer is entering its shutdown (S5) state. After all devices have entered their off (D3) state, the computer remains powered on until an administrator presses the power button.

### `StorPowerActionShutdownReset`

The computer is entering its shutdown (S5) state. After all devices have entered their off (D3) state, the computer automatically powers off and then immediately restarts and returns to its working (S0) state.

### `StorPowerActionShutdownOff`

The computer is entering its shutdown (S5) state. After all devices have entered their off (D3) state, the computer automatically powers off.

### `StorPowerActionWarmEject`

The computer is being ejected from an ACPI-compatible dock device. Typically, the computer's power state does not change.

## Remarks

For a unit, Storport sets **STOR_POWER_ACTION** in the
[**STOR_UNIT_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_unit_control_power) structure.

For an adapter, Storport sets **STOR_POWER_ACTION** in the [**STOR_ADAPTER_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_adapter_control_power) structure.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)