# DXGKDDI_CANCELCOMMAND callback function

## Description

Cleans up internal resources associated with a direct memory access (DMA) packet that was in the GPU scheduler's software queue but never reached the hardware queue because the device went into an error state. Such an error state is typically caused by a [Timeout Detection and Recovery (TDR)](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery) event.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCancelCommand`

A pointer to a [DXGKARG_CANCELCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_cancelcommand) structure that specifies resources to be cleaned up after a command is removed from the hardware queue.

## Return value

Returns **STATUS_SUCCESS** upon successful completion. If the driver instead returns an error code, the operating system causes a system bugcheck to occur. For more information, see the following Remarks section.

## Remarks

**Note** The DirectX graphics kernel subsystem calls this function only if the [DXGK_VIDSCHCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps).**CancelCommandAware** member is set.

If the driver returns an error code, the DirectX graphics kernel subsystem causes a system bugcheck to occur. In a crash dump file, the error is noted by the message **BugCheck 0x119**, which has the following four parameters.

1. 0x9
2. The NTSTATUS error code returned from the failed driver call
3. A pointer to the [DXGKARG_CANCELCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_cancelcommand) structure
4. A pointer to an internal scheduler data structure

## See also

[DXGKARG_CANCELCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_cancelcommand)

[DXGK_VIDSCHCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)