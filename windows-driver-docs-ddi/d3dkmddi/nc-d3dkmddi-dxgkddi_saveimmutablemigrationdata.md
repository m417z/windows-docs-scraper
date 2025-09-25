## Description

KMD's **DxgkDdiSaveImmutableMigrationData** function saves immutable data for a live migration that is about to start.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_GPUP_SAVE_IMMUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_save_immutable_migration_data) structure for information related to the call.

## Return value

**DxgkDdiSaveImmutableMigrationData** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

After calling KMD's [**DxgkDdiPrepareLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preparelivemigration) function, *Dxgkrnl* then calls**DxgkDdiSaveImmutableMigrationData** to gather information about the device to restore on the target side. This point is also an opportunity for the system to validate the configuration of the remote, so **DxgkDdiSaveImmutableMigrationData** should package up enough information to validate any hardware, firmware, or driver validation data that can detect the capability to move the VF over to the target configuration.

The driver should store data about the VF that won't change while it is alive that the target's KMD can use to help initialize the new VF. This data doesn't need to include the vGPU creation parameters, as those will be transferred in lower levels and used to create the vGPU using the normal DDI. This can include all data that is immutably tied to the VF, and doesn't all need to be restored on the target side. Data can be sent purely for validation purposes, which is a critical part of this interface.

**DxgkDdiSaveImmutableMigrationData** is called in the classic dynamic buffer pattern:

* On the first call, **DataSize** is set to 0 and **Data** to NULL. KMD should change **DataSize** to the total number of bytes it needs to store the immutable data.
* *Dxgkrnl* creates a buffer of **DataSize** bytes and makes a second call with **DataSize** set to the value returned by KMD and **Data** pointing to the allocated buffer. *Dxgkrnl* controls the lifetime of this allocated memory after the call.

[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata) is called at the end of a live migration to collect mutable data.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_SAVE_IMMUTABLE_MIGRATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_save_immutable_migration_data)

[**DxgkDdiPrepareLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preparelivemigration)

[**DxgkDdiSaveMutableMigrationData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_savemutablemigrationdata)