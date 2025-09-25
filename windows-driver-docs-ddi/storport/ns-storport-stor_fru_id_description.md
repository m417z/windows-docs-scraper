## Description

STOR_FRU_ID_DESCRIPTION is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitQueryFruId** or [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterQueryFruId**.

## Members

### `Version`

The version of this structure. Currently set to STOR_FRU_ID_DESCRIPTION_STRUCTURE_VERSION_1.

### `Size`

Total size of this structure, in bytes. Must be >= ```sizeof(STOR_FRU_ID_DESCRIPTION)```.

### `Address`

Pointer to a [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address) structure containing the address of the logical unit (LUN).

### `FruId`

The ID of the fault replacement unit (FRU). The FRU ID is the identifier physically printed on the hardware to uniquely identify it. **FruId** must be <= 128 ASCII characters.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address)