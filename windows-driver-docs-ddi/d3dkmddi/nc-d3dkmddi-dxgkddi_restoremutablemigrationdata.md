## Description

The receiving-side OS calls **DxgkDdiRestoreMutableMigrationData** to restore mutable data that was saved by the sending-side driver in a previous call to [**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata).

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in] Pointer to a [**DXGKARG_GPUP_RESTORE_MUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_restore_mutable_migration_data) structure that contains information needed to restore the mutable data.

## Return value

**DxgkDdiRestoreImmutableMigrationData** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

This DDI should only ever be called for VFs that are currently paused.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_RESTORE_MUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_restore_mutable_migration_data)

[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata)