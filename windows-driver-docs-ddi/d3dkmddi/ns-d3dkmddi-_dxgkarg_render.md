# _DXGKARG_RENDER structure

## Description

The DXGKARG_RENDER structure describes members for generating a direct memory access (DMA) buffer from a command buffer.

## Members

### `pCommand` [in]

A pointer to the start of the command buffer.

**Note** When [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) is called, the display miniport driver must validate the buffer. See Remarks in **DxgkDdiRender** for important info on how the driver should access this member.

### `CommandLength` [in]

The size, in bytes, of the command buffer that **pCommand** points to.

### `pDmaBuffer` [out]

A pointer to the start of the DMA buffer, which is aligned on 4 KB. This buffer can be sent through DMA to the graphics hardware. Before the display miniport driver returns from the [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) or [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) functions, the driver should set **pDmaBuffer** to the next empty byte that follows the last byte that the driver wrote to, or the driver should point to the location (one byte beyond the buffer space) if no more space is available. This location would have been correct if the buffer was large enough.

### `DmaSize` [in]

The size, in bytes, of the DMA buffer that **pDmaBuffer** points to.

### `pDmaBufferPrivateData` [in]

A pointer to a driver-resident private data structure that is used for generating the DMA buffer that **pDmaBuffer** points to.

### `DmaBufferPrivateDataSize` [in]

The number of bytes that remain in the private data structure that **pDmaBufferPrivateData** points to for the current operation.

### `pAllocationList` [in]

An array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures for the list of allocations that the DMA buffer references. Each allocation that is referenced should appear once for optimal performance.

### `AllocationListSize` [in]

The available number of elements in the array that **pAllocationList** specifies, which represents the number of allocation specifications to send through DMA to the graphics hardware.

### `pPatchLocationListIn` [in]

An array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the patch-location list that the user-mode display driver provides in a call to the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

**Note** When [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) is called, the display miniport driver must validate the buffer. See Remarks in **DxgkDdiRender** for important info on how the driver should access this member.

### `PatchLocationListInSize` [in]

The number of elements in the patch-location list that **pPatchLocationListIn** specifies.

### `pPatchLocationListOut` [in/out]

An array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the patch-location list that the display miniport driver fills in. Before the driver returns from a call to its [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) or [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) functions, the driver must set **pPatchLocationListOut** to the next **D3DDDI_PATCHLOCATIONLIST** element that follows the last **D3DDDI_PATCHLOCATIONLIST** element that the driver updated.

### `PatchLocationListOutSize` [in]

The number of elements in the patch-location list that **pPatchLocationListOut** specifies. The display miniport driver is not required to fill all of the elements in the entire list; the driver must use only elements that are necessary to describe the patch location within the DMA buffer.

### `MultipassOffset` [in/out]

A UINT value that specifies the progress of the rendering operation if the display miniport driver's [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) or [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) functions must return **STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER** to obtain a new DMA buffer. When the driver's *DxgkDdiRender* or *DxgkDdiRenderKm* function is first called with a new command buffer, **MultipassOffset** is initialized to zero. Before the driver returns from the *DxgkDdiRender* or *DxgkDdiRenderKm* calls, the driver sets this member to show translation progress for subsequent *DxgkDdiRender* or *DxgkDdiRenderKm* call with the same command buffer. The DirectX graphics kernel subsystem does not change the value further.

### `DmaBufferSegmentId` [in]

The identifier of the memory segment that the DMA buffer was paged in. If the identifier is zero, the DMA buffer is not correctly paged in.

### `DmaBufferPhysicalAddress` [in]

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address where the DMA buffer was paged in. If the physical address is zero, the DMA buffer is not correctly paged in.

## Remarks

 Support for the [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function is added beginning with Windows 7 for display adapters that support [GDI Hardware Acceleration](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-hardware-acceleration).

## See also

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)