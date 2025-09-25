## Description

**STOR_MAX_OPERATIONAL_POWER** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPoFxMaxOperationalPower**.

## Members

### `Version`

Version of this structure. This is currently set to 1.

### `Size`

Size of this structure, in bytes. Set to ```sizeof(STOR_MAX_OPERATIONAL_POWER)```.

### `Value`

The maximum operational power value. **Value** in each power state (P-State) must represent a maximum power level that is relative in proportion to the other P-States.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)