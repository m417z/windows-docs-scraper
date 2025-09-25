# DXGKDDI_SETPOINTERPOSITION callback function

## Description

The *DxgkDdiSetPointerPosition* function sets the location and visibility state of the mouse pointer.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetPointerPosition` [in]

A pointer to a [DXGKARG_SETPOINTERPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointerposition) structure that describes where and how to display the mouse pointer.

## Return value

*DxgkDdiSetPointerPosition* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiSetPointerPosition* function to set the location of the mouse pointer. The *DxgkDdiSetPointerPosition* function is called independently of all of the other display miniport driver functions. Therefore, a *DxgkDdiSetPointerPosition* thread can run simultaneously with another display miniport driver thread. However, the system ensures that *DxgkDdiSetPointerPosition* and [DxgkDdiSetPointerShape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointershape) threads cannot run simultaneously.

If you run a *DxgkDdiSetPointerPosition* thread simultaneously with another display miniport driver thread, the display miniport driver should be able to program the mouse pointer hardware independently of other activities, such as operations that send a command buffer through direct memory access (DMA) to the graphics hardware, operations that program the graphics hardware by using memory-mapped I/O (MMIO), and so on.

*DxgkDdiSetPointerPosition* can be called even if the video present network (VidPN) topology that is associated with the **VidPnSourceId** member of the [DXGKARG_SETPOINTERPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointerposition) structure that the *pSetPointerPosition* parameter points to is disabled. In this case, the driver should return STATUS_SUCCESS but should make no changes to the state of the driver or hardware.

*DxgkDdiSetPointerPosition* should be made pageable.

## See also

[DXGKARG_SETPOINTERPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointerposition)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiSetPointerShape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointershape)