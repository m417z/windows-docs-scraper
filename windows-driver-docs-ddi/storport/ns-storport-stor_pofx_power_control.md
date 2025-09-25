## Description

**STOR_POFX_POWER_CONTROL** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitPoFxPowerControl** or [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPoFxPowerControl**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `PowerControlCode`

A power control code GUID identifying the private control operation to execute for the unit or adapter.

### `InBufferSize`

The size, in bytes, of the input buffer at **InBuffer**.

### `OutBufferSize`

The size, in bytes, of the output buffer at **OutBuffer**.

### `InBuffer`

Pointer to the buffer containing input parameters and data for the private power control call.

### `OutBuffer`

Pointer to the buffer where the resulting output parameters and data are returned for the private power control call.

### `BytesReturned`

The size, in bytes, of the data returned in **OutBuffer**.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header)