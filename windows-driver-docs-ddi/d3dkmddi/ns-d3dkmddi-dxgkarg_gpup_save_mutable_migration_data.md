## Description

The **DXGKARG_GPUP_SAVE_MUTABLE_MIGRATION_DATA** structure is used in a call to [**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata) to save mutable data for a live migration that is about to end.

## Members

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

### `DataSize`

[in/out] The size, in bytes, of the data buffer that **Data** points to. On the first call to[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata), the input value is 0 to indicate that the driver should return the required size of the buffer.

### `Data`

[in/out] A pointer to a buffer that contains the mutable data to be saved. On the first call to [**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata), this pointer is NULL to indicate that the driver should return the required size of the buffer in **DataSize**.

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata)