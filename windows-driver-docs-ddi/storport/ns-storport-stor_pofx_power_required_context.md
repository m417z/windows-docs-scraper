## Description

**STOR_POFX_POWER_REQUIRED_CONTEXT** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitPoFxPowerRequired**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `PowerRequired`

**TRUE** if the unit component requires power. Otherwise, **FALSE.**

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header)