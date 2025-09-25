## Description

**STOR_POFX_UNIT_POWER_INFO** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitPoFxPowerInfo**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `IdlePowerEnabled`

**TRUE** if idle power management is enabled for the unit. Otherwise, **FALSE**.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header)