# _DXGK_CONTEXTINFO structure

## Description

The DXGK_CONTEXTINFO structure describes a device context.

## Members

### `DmaBufferSize`

The size, in bytes, of the buffer of hardware commands that is sent through direct memory access (DMA) to the graphics processing unit (GPU).

The DMA buffer can grow and shrink after the context is created; however, the DMA buffer can never shrink smaller than the starting size that **DmaBufferSize** specifies.

### `DmaBufferSegmentSet`

 The identifiers of the segments where the DMA buffer should be made accessible to the GPU.

### `DmaBufferPrivateDataSize`

The size, in bytes, of the driver-resident private data structure that is associated with each DMA buffer. Memory for this private data structure is allocated from nonpaged pool. If the driver specifies zero in **DmaBufferPrivateDataSize**, no memory is allocated for the private data structure.

The private data structure that is associated with a DMA buffer is initialized to zero when the DMA buffer is created. During the lifetime of the DMA buffer, the video memory manager never accesses the private data structure that is associated with the DMA buffer.

### `AllocationListSize`

The starting number of elements in an array of allocations (that is, an array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures). This number is the starting number of allocations that the driver requests to be in the **pAllocationList** members of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) and [DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structures in calls to the driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) and [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) functions, respectively.

The allocation list can grow and shrink after the context is created; however, the allocation list can never shrink smaller than the starting size that **AllocationListSize** specifies.

**Note** If [DXGK_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags).**GdiContext** is set to 1, meaning that the context is created as a GDI-specific context, **AllocationListSize** must be set to a value of 256.

### `PatchLocationListSize`

 The starting number of elements in an array of patch locations (that is, an array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures) for the device in user mode and kernel mode. This number is the starting number of patch locations that the driver requests to be in the **pPatchLocationListIn** members of the [DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structures in calls to its [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function.

The patch-location list can grow and shrink after the context is created; however, the patch-location list can never shrink smaller than the starting size that **PatchLocationListSize** specifies.

### `Reserved`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `Caps`

Describes optional features supported by the context.

Supported starting with Windows 10.

### `PagingCompanionNodeId`

Specifies the zero-based engine identifier of the engine to use for this context paging companion.

Supported starting with Windows 10.

## Remarks

A display miniport driver specifies values for the **DmaBufferSize** and **AllocationListSize** members to guarantee that:

* The Microsoft DirectX graphics subsystem can use only one direct memory access (DMA) buffer to display (by using the display miniport driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function) at least one [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for all scenarios.
* The sizes of DMA and allocation-list buffers are large enough to hold at least one command that cannot be split across multiple buffers.
* The sizes of DMA and allocation-list buffers are large enough to avoid setup and DMA overhead.

The display miniport driver can specify only aperture segments in the **DmaBufferSegmentSet** member; if the driver specifies a memory segment, a context-creation failure occurs.

If the driver sets **DmaBufferSegmentSet** to 0, the video memory manager allocates contiguous paged-locked memory, which is mapped write-combined memory, for the DMA buffers. Therefore, the GPU must access DMA buffers by using PCI cycles on computers where AGP transfers that occur outside the AGP aperture are not permitted.

## See also

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[DXGKARG_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)

[DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DXGK_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)