## Description

*Dxgkrnl* calls KMD's **DxgkDdiEndLiveMigration** function to notify the driver that a live migration is ending.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

## Return value

**DxgkDdiEndLiveMigration** returns STATUS_SUCCESS if it succeeds; otherwise, it returns an appropriate NTSTATUS code.

## Remarks

**DxgkDdiEndLiveMigration** is called when there is no more need for migration configuration on the specified VF. All scheduling and state should return to a non-migrating configuration.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DxgkDdiPrepareLiveMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preparelivemigration)