## Description

KMD's **DxgkDdiSaveMutableMigrationData** function collects mutable data for a live migration that is about to end.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_GPUP_SAVE_MUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_save_mutable_migration_data) structure for information related to the call.

## Return value

**DxgkDdiSaveMutableMigrationData** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata) is called to collect mutable data when a live migration is about to end. This DDI should only ever be called for VFs that are currently paused.

**DxgkDdiSaveMutableMigrationData** is called in the classic dynamic buffer pattern:

* On the first call, **DataSize** is set to 0 and **Data** to NULL. KMD should change **DataSize** to the total number of bytes it needs to store the immutable data.
* *Dxgkrnl* creates a buffer of **DataSize** bytes and makes a second call with **DataSize** set to the value returned by KMD and **Data** pointing to the allocated buffer. *Dxgkrnl* controls the lifetime of this allocated memory after the call.

[**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata) is called at the start of a live migration to collect immutable data.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_SAVE_MUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_save_immutable_migration_data)

[**DxgkDdiSaveImmutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_saveimmutablemigrationdata)