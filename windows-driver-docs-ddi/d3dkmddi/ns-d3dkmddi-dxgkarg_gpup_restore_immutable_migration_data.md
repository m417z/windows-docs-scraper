## Description

The **DXGKARG_GPUP_RESTORE_IMMUTABLE_MIGRATION_DATA** structure is used in a call to [**DxgkDdiRestoreImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_restoreimmutablemigrationdata) to restore immutable data that was saved by the sending-side driver in a previous call to its [**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata).

## Members

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

### `DataSize`

[in] Size of the buffer that **Data** points to, in bytes.

### `Data`

[in] Pointer to the buffer containing the immutable migration data collected and sent from the source system that is to be restored on the target.

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DxgkDdiRestoreImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_restoreimmutablemigrationdata)

[**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata)