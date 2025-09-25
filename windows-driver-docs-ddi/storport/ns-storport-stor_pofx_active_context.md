## Description

**STOR_POFX_ACTIVE_CONTEXT** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitPoFxPowerActive** or a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPoFxPowerActive**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `ComponentIndex`

Index of the device component with the active status. The component index is always 0 for a unit device and for an adapter.

### `Active`

The active status of the component. For a unit device, **Active** is set to **TRUE** if the unit is active or **FALSE** if the unit is idle. For an adapter, **Active** is always set to **TRUE**.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header)