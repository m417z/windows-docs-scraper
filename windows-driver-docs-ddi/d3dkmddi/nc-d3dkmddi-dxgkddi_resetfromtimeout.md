# DXGKDDI_RESETFROMTIMEOUT callback function

## Description

The *DxgkDdiResetFromTimeout* function resets the graphics processing unit (GPU) after a hardware timeout occurs and guarantees that the GPU is not writing or reading any memory by the time that *DxgkDdiResetFromTimeout* returns.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

## Return value

*DxgkDdiResetFromTimeout* returns STATUS_SUCCESS to indicate that the driver handled the call successfully; otherwise, the operating system bug checks and causes a restart.

## Remarks

The GPU scheduler calls *DxgkDdiResetFromTimeout* when it detects that a hardware time-out occurred. The time-out is typically a delayed response to a preempt request. *DxgkDdiResetFromTimeout* should reset the GPU.

For more information about time-outs in this situation, see [Thread Synchronization and TDR](https://learn.microsoft.com/windows-hardware/drivers/display/thread-synchronization-and-tdr).

*DxgkDdiResetFromTimeout* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiReleaseSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_releaseswizzlingrange)

[DxgkDdiRestartFromTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_restartfromtimeout)