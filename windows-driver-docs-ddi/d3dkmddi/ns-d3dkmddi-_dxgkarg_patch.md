# _DXGKARG_PATCH structure

## Description

The DXGKARG_PATCH structure describes a direct memory access (DMA) buffer that requires patching (that is, requires the assignment of physical addresses).

## Members

### `hDevice` [in]

If a driver is not multiple-engine aware (that is, the driver does not support context creation), a handle to the display device (graphics context) that the submission request originated from. A device handle is supplied to the driver's [DxgkDdiPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function in the union that DXGKARG_PATCH contains.

For some paging operations, **hDevice** is **NULL** (for example, paging operations that evict the content of the entire frame buffer during power management). Paging operations are indicated by the **Paging** bit-field flag in the **Flags** member.

### `hContext` [in]

If the driver is multiple-engine aware (that is, the driver supports context creation), a handle to the device context that the submission request originated from. A context handle is supplied to the driver's [DxgkDdiPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function in the union that DXGKARG_PATCH contains.

For some paging operations, **hContext** is **NULL** (for example, paging operations that evict the content of the entire frame buffer during power management). Paging operations are indicated by the **Paging** bit-field flag in the **Flags** member.

### `DmaBufferSegmentId` [in]

The identifier of the memory segment that the DMA buffer was paged in.

The identifier can be zero if the driver indicated not to map the DMA buffer into the segment by setting the **DmaBufferSegmentSet** member of the [DXGK_CONTEXTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo) structure to 0 in a call to the driver's [DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function. If **DmaBufferSegmentId** is zero, the DMA buffer was allocated as a contiguous block of system memory.

### `DmaBufferPhysicalAddress` [in]

A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the physical address where the DMA buffer was paged in.

If **DmaBufferSegmentId** is zero, **DmaBufferPhysicalAddress** is the physical address in system memory where the DMA buffer is located.

If **DmaBufferSegmentId** is nonzero, **DmaBufferPhysicalAddress** is the segment physical address for the DMA buffer (that is, DXGK_SEGMENTDESCRIPTOR.BaseAddress + DmaBuffer.SegmentOffset).

Note that **DmaBufferPhysicalAddress** always refers to the beginning of the DMA buffer even though the driver might be required to patch or submit a section of the DMA buffer that does not include the beginning of the DMA buffer (that is, if the **DmaBufferSubmissionStartOffset** member is nonzero).

### `pDmaBuffer` [in]

A pointer to the start of the DMA buffer (that is, the virtual address of the beginning of the DMA buffer).

### `DmaBufferSize` [in]

The size, in bytes, of the DMA buffer that **pDmaBuffer** points to.

Note that **DmaBufferSize** represents the entire length of the DMA buffer; however, the request to patch or submit might refer to only a portion of the DMA buffer.

### `DmaBufferSubmissionStartOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer that **pDmaBuffer** specifies to the start of the portion of the DMA buffer that requires patching or submitting. The offset that is received at patch time matches the offset that is received at submission time.

### `DmaBufferSubmissionEndOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer that **pDmaBuffer** specifies to the end of the portion of the DMA buffer that requires patching or submitting. The offset that is received at patch time matches the offset that is received at submission time.

### `pDmaBufferPrivateData` [in]

A pointer to the driver-resident private data that is associated with the DMA buffer that **pDmaBuffer** points to.

For paging operations, a single paging buffer is used for multiple independent submissions. In that scenario, the driver can indicate—by returning the appropriate private driver data pointer in a call to its [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function—to have either a single driver private data range for all submissions or one for each submission.

### `DmaBufferPrivateDataSize` [in]

The size, in bytes, of the private driver data at **pDmaBufferPrivateData**.

Note that **DmaBufferPrivateDataSize** represents the entire length of the private driver data buffer; however, the portion that is associated with the current submission might be smaller.

### `DmaBufferPrivateDataSubmissionStartOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the start of the portion of the private data that is associated with the current submission. **DmaBufferPrivateDataSubmissionStartOffset** is always zero for a nonpaging request.

### `DmaBufferPrivateDataSubmissionEndOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the end of the portion of the private data that is associated with the current submission.

### `pAllocationList` [in]

A pointer to an array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures for the list of allocations that is associated with the DMA buffer that **pDmaBuffer** points to.

For paging operations, **pAllocationList** is **NULL** because paging buffers are not associated with allocation lists.

### `AllocationListSize` [in]

The number of elements in the array that **pAllocationList** specifies.

Note that **AllocationListSize** represents the total size of the allocation list; however, the portion of the allocation list that is associated with the current submission might be smaller.

Note that for paging operations **AllocationListSize** is zero because paging buffers are not associated with allocation lists.

### `pPatchLocationList` [in]

A pointer to an array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the list of patch locations that is associated with the DMA buffer that **pDmaBuffer** points to.

Note that the array can begin with an element that is before the range that is used to patch the DMA buffer.

For paging operations, **pPatchLocationList** is **NULL** because paging buffers are not associated with patch-location lists.

### `PatchLocationListSize` [in]

The number of elements in the array that **pPatchLocationList** specifies.

Note that **PatchLocationListSize** represents the total size of the patch-location list; however, the range that the driver must process is typically smaller.

For paging operations, **PatchLocationListSize** is zero because paging buffers are not associated with patch-location lists.

### `PatchLocationListSubmissionStart` [in]

The index of the first element in the patch-location list that **pPatchLocationList** specifies that must be processed.

For paging operations, **PatchLocationListSubmissionStart** is zero.

### `PatchLocationListSubmissionLength` [in]

The number of elements in the patch-location list that **pPatchLocationList** specifies that must be processed.

For paging operations, **PatchLocationListSubmissionLength** is zero.

### `SubmissionFenceId` [in]

A unique identifier that the driver can write into the fence command at the end of the DMA buffer. For more information about this type of identifier, see [Supplying Fence Identifiers](https://learn.microsoft.com/windows-hardware/drivers/display/supplying-fence-identifiers).

### `Flags` [in]

A [DXGK_PATCHFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_patchflags) structure that identifies information about the DMA buffer that requires patching.

### `EngineOrdinal` [in]

Reserved for future use.

## Remarks

The display miniport driver returns an array in the **pAllocationList** member of a [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) or [DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structure from its [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) or [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function after it translates the command buffer to a direct memory access (DMA) buffer. The video memory manager assigns physical addresses to the **PhysicalAddress** members of the [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures in the array and passes this array to the driver's [DxgkDdiPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function. **DxgkDdiPatch** patches places in the DMA buffer with these physical addresses.

## See also

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)

[DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DXGK_CONTEXTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo)

[DXGK_PATCHFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_patchflags)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)

[DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[DxgkDdiPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)