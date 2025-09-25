## Description

The **DXGKARG_GPUP_SAVE_IMMUTABLE_MIGRATION_DATA** structure is used in a call to [**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata) to save immutable data for a live migration that is about to start.

## Members

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

### `DataSize`

[in/out] The size, in bytes, of the data buffer that **Data** points to. On the first call to[**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata), the input value is 0 to indicate that the driver should return the required size of the buffer.

### `Data`

[in/out] A pointer to a buffer that contains the immutable data to be saved. On the first call to [**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata), this pointer is NULL to indicate that the driver should return the required size of the buffer in **DataSize**.

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata)