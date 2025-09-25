## Description

The **DXGKARG_GPUP_PREPARE_LIVE_MIGRATION** structure contains information for the KMD's [**DxgkDdiPrepareLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preparelivemigration) function to prepare for a live migration.

## Members

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

### `MigrationType`

[in] A [**DXGK_GPUP_MIGRATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_gpup_migrationtype) enumeration that specifies the type of migration that is about to start.

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGK_GPUP_MIGRATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_gpup_migrationtype)

[**DxgkDdiPrepareLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preparelivemigration)