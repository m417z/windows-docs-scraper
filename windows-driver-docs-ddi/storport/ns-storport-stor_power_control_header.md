## Description

**STOR_POWER_CONTROL_HEADER** is a common power control header for both adapter and unit power-related control parameters.

## Members

### `Version`

The version of the parent structure. Set to 1.

### `Size`

Size of the parent structure, in bytes. For example, if the parent structure is **STOR_ADAPTER_CONTROL_POWER**, set **Size** to ```sizeof(STOR_ADAPTER_CONTROL_POWER)```.

### `Address`

For a unit, **Address** points to a [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address) structure that holds the address of the unit the control operation is specified for. For adapters, **Address** is NULL.

## Remarks

**STOR_POWER_CONTROL_HEADER** is used when [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) and [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) are called with power-related controls.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_ADAPTER_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_adapter_control_power)

[**STOR_POFX_ACTIVE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_active_context)

[**STOR_POFX_FSTATE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_fstate_context)

[**STOR_POFX_POWER_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_power_control)

[**STOR_POFX_POWER_REQUIRED_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_power_required_context)

[**STOR_POFX_UNIT_POWER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_unit_power_info)