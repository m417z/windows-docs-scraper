# DXGKDDI_SETPOINTERSHAPE callback function

## Description

The *DxgkDdiSetPointerShape* function sets the appearance and location of the mouse pointer.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetPointerShape` [in]

A pointer to a [DXGKARG_SETPOINTERSHAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointershape) structure that describes the appearance and location of the mouse pointer.

## Return value

*DxgkDdiSetPointerShape* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mouse pointer is successfully drawn.|
|STATUS_NO_MEMORY|DxgkDdiSetPointerShape could not allocate memory that was required for it to complete.|

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiSetPointerShape* function to set information about the mouse pointer. The *DxgkDdiSetPointerShape* function is called independently of all of the other display miniport driver functions. Therefore, a *DxgkDdiSetPointerShape* thread can run simultaneously with another display miniport driver thread. However, the system ensures that *DxgkDdiSetPointerShape* and [DxgkDdiSetPointerPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointerposition) threads cannot run simultaneously.

If you run a *DxgkDdiSetPointerShape* thread simultaneously with another display miniport driver thread, the display miniport driver should be able to program the mouse pointer hardware independently of other activities, such as operations that send a command buffer through direct memory access (DMA) to the graphics hardware, operations that program the graphics hardware by using memory-mapped I/O (MMIO), and so on.

*DxgkDdiSetPointerShape* is not called if the video present network (VidPN) topology that is associated with the **VidPnSourceId** member of the [DXGKARG_SETPOINTERSHAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointershape) structure that the *pSetPointerShape* parameter points to is disabled.

*DxgkDdiSetPointerShape* should be made pageable.

## See also

[DXGKARG_SETPOINTERSHAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointershape)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiSetPointerPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointerposition)