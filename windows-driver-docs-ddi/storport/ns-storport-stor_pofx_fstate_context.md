## Description

**STOR_POFX_FSTATE_CONTEXT** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitPoFxPowerSetFState** or [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPoFxPowerSetFState**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `ComponentIndex`

Index of the device component with the active status. The component index is always 0 for both a unit device and an adapter.

### `FState`

The F-state to set for the unit or adapter component. For an adapter, the F0 state is the only component power state set.

## Remarks

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header)