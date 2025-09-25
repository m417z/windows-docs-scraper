# DXGKDDI_RESETENGINE callback function

## Description

The display port driver's GPU scheduler calls the miniport driver's (KMD's) **DxgkDdiResetEngine** function to reset an active node on a physical display adapter when the scheduler detects a timeout condition on the adapter.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pResetEngine`

[in/out] A [**DXGKARG_RESETENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resetengine) structure that specifies the node to be reset and supplies a fence identifier for the last aborted packet.

## Return value

**DxgkDdiResetEngine** returns STATUS_SUCCESS if the function succeeds. Otherwise, this function returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The KMD should return from a call to this function only when all of the following criteria are met:

* The reset operation is completed.
* Nothing remains in the physical adapter's hardware queue.
* The specified nodes are ready to accept new packets.

This function should be made pageable.

The operating system guarantees that this function follows the [first level synchronization mode](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-first-level).

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[**DXGKARG_RESETENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resetengine)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)