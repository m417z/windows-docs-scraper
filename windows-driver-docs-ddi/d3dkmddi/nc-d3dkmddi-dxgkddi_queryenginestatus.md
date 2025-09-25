# DXGKDDI_QUERYENGINESTATUS callback function

## Description

The display port driver's GPU scheduler calls this function to determine the progress of a node within an active physical display adapter (engine).

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pQueryEngineStatus`

A pointer to a [DXGKARG_QUERYENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryenginestatus) structure that specifies a node and physical adapter that are to be queried for progress, and that supplies a value for the progress.

## Return value

Returns STATUS_SUCCESS if the function succeeds. Otherwise, this function returns one of the error codes defined in Ntstatus.h.

## Remarks

 This function should be made pageable, and it should always succeed.

The operating system guarantees that this function follows the first level synchronization mode as defined in [Threading and Synchronization First Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-first-level).

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[DXGKARG_QUERYENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryenginestatus)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)