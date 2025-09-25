## Description

*Dxgkrnl* calls KMD's **DxgkDdiPrepareLiveMigration** function to notify the driver to prepare for a live migration that is about to start.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in] A pointer to a [**DXGKARG_GPUP_PREPARE_LIVE_MIGRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_prepare_live_migration) structure that contains the information required to prepare for a live migration.

## Return value

**DxgkDdiPrepareLiveMigration** returns STATUS_SUCCESS if it succeeds; otherwise, it returns an appropriate NTSTATUS code.

## Remarks

A call to **DxgkDdiPrepareLiveMigration** allows the driver to configure the virtual function (VF), its scheduling, its own internal state, and anything else needed around managing the migration. The intent of this call is to establish the PF/VF scheduling policies that provide for the live migration’s ability to stream dirty content from the VRAM in the host while preserving fair performance for the VF. If the dirty tracking is reported as nonperformant, this callback is also where the dirty tracking is started.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_PREPARE_LIVE_MIGRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_prepare_live_migration)

[**DxgkDdiEndLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_endlivemigration)