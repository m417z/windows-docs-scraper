# DXGKARG_BUILDPAGINGBUFFER structure

## Description

The **DXGKARG_BUILDPAGINGBUFFER** structure describes parameters for the [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) callback that builds a paging buffer for use in a memory-transfer operation.

## Members

### `pDmaBuffer`

[in/out] A virtual address to the first available byte in the paging buffer. When the driver is first called with a new paging buffer, this virtual address is aligned on 4 KB. The driver tightly packs operations in the paging buffer until the paging buffer is full and then uses a new paging buffer. Therefore, if the graphics processing unit (GPU) requires a specific alignment for a paging-buffer submission, the driver should enforce this alignment by padding the operations that it writes to the paging buffer. Before the [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function returns, the driver should update **pDmaBuffer** to point past the last byte that is written to the paging buffer.

### `DmaSize`

[in/out] The size, in bytes, of the paging buffer that **pDmaBuffer** specifies.

### `pDmaBufferPrivateData`

[in/out] A pointer to a driver-resident private data structure that is associated with the direct memory access (DMA) buffer (that is, paging buffer) that **pDmaBuffer** specifies.

### `DmaBufferPrivateDataSize`

[in/out] The number of bytes that remain in the private data structure that **pDmaBufferPrivateData** points to for the current operation.

### `Operation`

[in] A [**DXGK_BUILDPAGINGBUFFER_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation)-typed value that indicates the type of memory operation to perform.

### `MultipassOffset`

[in/out] A UINT value that specifies the progress of the paging operation if multiple paging buffers are required. The driver sets this value to indicate a split into multiple paging buffers for more than one transfer operation. For example, the driver can store the page number that was last transferred for a paged-based transfer.

### `Transfer`

[in] A structure that describes the transfer operation.

### `Transfer.hAllocation`

[in] A handle to the allocation that the driver's [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function previously returned in the **hAllocation** member of a [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure, which is part of the [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure's **pAllocationInfo** member. The allocation handle points to a buffer that contains private driver data for the transfer.

### `Transfer.TransferOffset`

[in] The offset, in bytes, of the first page within the allocation that is transferred. This offset is applied only to a location that a segment location describes. This offset does not apply to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) description of a memory range. If the driver requires more than one paging buffer to complete the transfer (that is, the driver returns STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER from its [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function), **TransferOffset** is the same for each call to **DxgkDdiBuildPagingBuffer** for this transfer.

### `Transfer.TransferSize`

[in] The size, in bytes, of the memory information to transfer.

### `Transfer.Source`

[in] A structure that describes the source allocation. This structure contains a **SegmentId** member and a union that contains either an offset into a segment of the source allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the source (**pMdl**).

### `Transfer.Source.SegmentId`

[in] The identifier of a segment within the source allocation, or zero if the source allocation is described by the **pMdl** member of the union that **Source** contains.

### `Transfer.Source.SegmentAddress`

[in] The source segment address, if the **SegmentId** member of **Source** is nonzero. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `Transfer.Source.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the system memory pages for the source, if the **SegmentId** member of **Source** is zero.

### `Transfer.Destination`

[in] A structure that describes the destination allocation. This structure contains a **SegmentId** member and a union that contains either an offset into a segment of the destination allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the destination (**pMdl**).

### `Transfer.Destination.SegmentId`

[in] The identifier of a segment within the destination allocation, or zero if the destination allocation is described by the **pMdl** member of the union that **Destination** contains.

### `Transfer.Destination.SegmentAddress`

[in] The destination segment address, if the **SegmentId** member of **Destination** is nonzero. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `Transfer.Destination.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the system memory pages for the destination, if the **SegmentId** member of **Destination** is zero.

### `Transfer.Flags`

[in] A [**DXGK_TRANSFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_transferflags) structure that identifies, in bit-field flags, the type of special-lock-transfer operation to perform.

### `Transfer.MdlOffset`

[in] The offset, in system memory pages, within the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that the **pMdl** member points to, to the first system memory page for the current operation. The driver can obtain the physical address of the first system memory page by calling the [**MmGetMdlPfnArray**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetmdlpfnarray) function as follows.

```cpp
MmGetMdlPfnArray(pMdl)[MdlOffset];
```

### `Fill`

[in] A structure that describes the fill operation.

### `Fill.hAllocation`

[in] A handle to the allocation that contains content to fill.

### `Fill.FillSize`

[in] The size, in bytes, of the memory information to fill.

### `Fill.FillPattern`

[in] The pattern to fill the destination with. The video memory manager uses this information to initialize video memory to a specific pattern when an allocation without content is first paged in. In this case, no source exists for the fill request—only a destination exists.

### `Fill.Destination`

[in] A structure that describes the destination allocation for the fill operation.

### `Fill.Destination.SegmentId`

[in] The identifier of a segment within the destination allocation.

### `Fill.Destination.SegmentAddress`

[in] The destination segment address. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `DiscardContent`

[in] A structure that describes the discard-content operation.

### `DiscardContent.hAllocation`

[in] A handle to the allocation that contains content to discard.

### `DiscardContent.Flags`

[in] A [**DXGK_DISCARDCONTENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_discardcontentflags) structure that identifies, in bit-field flags, the type of discard-content operation to perform.

### `DiscardContent.SegmentId`

[in] The identifier of a segment within the allocation to discard content from.

### `DiscardContent.SegmentAddress`

[in] A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the segment address. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```. This location is where content is discarded from.

### `ReadPhysical`

[in] A structure that describes the read-physical operation.

### `ReadPhysical.SegmentId`

[in] The identifier of a segment that data is read from.

### `ReadPhysical.PhysicalAddress`

[in] A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the physical address, within the segment that **SegmentId** specifies, where the data is read.

### `WritePhysical`

[in] A structure that describes the write-physical operation.

### `WritePhysical.SegmentId`

[in] The identifier of a segment to which data is written.

### `WritePhysical.PhysicalAddress`

[in] A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the physical address, within the segment that **SegmentId** specifies, where the data is written.

### `MapApertureSegment`

[in] A structure that describes the map-aperture-segment operation using an MDL.

### `MapApertureSegment.hDevice`

[in] A handle to the device that owns the allocation that **hAllocation** specifies that is mapped into the aperture segment that **SegmentId** specifies.

For a shared allocation, **hDevice** is set to the device that the video memory manager determined to be the owner of the allocation.

**hDevice** is **NULL** for the primary allocation.

### `MapApertureSegment.hAllocation`

[in] A handle to the allocation that is mapped into the aperture segment that **SegmentId** specifies.

**hAllocation** is **NULL** when a DMA buffer is mapped into the aperture segment because DMA buffers are not explicitly created by the driver.

### `MapApertureSegment.SegmentId`

[in] The identifier of an aperture segment to configure.

### `MapApertureSegment.OffsetInPages`

[in] The offset, in pages, from the beginning of the segment to the first pages to map.

### `MapApertureSegment.NumberOfPages`

[in] The number of pages to map.

### `MapApertureSegment.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the physical system memory pages to map into the aperture segment.

### `MapApertureSegment.Flags`

[in] A [**DXGK_MAPAPERTUREFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_mapapertureflags) structure that identifies, in bit-field flags, the type of map-aperture-segment operation to perform.

### `MapApertureSegment.MdlOffset`

[in] The offset, in system memory pages, within the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that the **pMdl** member points to, to the first system memory page for the current operation. The driver can obtain the physical address of the first system memory page by calling the [**MmGetMdlPfnArray**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetmdlpfnarray) function as follows.

```cpp
MmGetMdlPfnArray(pMdl)[MdlOffset];
```

### `UnmapApertureSegment`

[in] A structure that describes the unmap-aperture-segment operation.

### `UnmapApertureSegment.hDevice`

[in] A handle to the device that owns the allocation that **hAllocation** specifies that is unmapped from the aperture segment that **SegmentId** specifies.

For a shared allocation, **hDevice** is set to the device that the video memory manager determined to be the owner of the allocation.

**hDevice** is **NULL** for the primary allocation.

### `UnmapApertureSegment.hAllocation`

[in] A handle to the allocation that is unmapped from the aperture segment that **SegmentId** specifies.

**hAllocation** is **NULL** when a DMA buffer is unmapped from the aperture segment because DMA buffers are not explicitly created by the driver.

### `UnmapApertureSegment.SegmentId`

[in] The identifier of an aperture segment to configure.

### `UnmapApertureSegment.OffsetInPages`

[in] The offset, in pages, from the beginning of the segment to the first pages to unmap.

### `UnmapApertureSegment.NumberOfPages`

[in] The number of pages to unmap.

### `UnmapApertureSegment.DummyPage`

[in] A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the physical address of the placeholder page where the driver should map the range that is unmapped.

### `SpecialLockTransfer`

[in] A structure that describes the special-lock-transfer operation.

### `SpecialLockTransfer.hAllocation`

[in] A handle to the allocation that the driver's [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function previously returned in the **hAllocation** member of a [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure, which is part of the [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure's **pAllocationInfo** member. The allocation handle points to a buffer that contains private driver data for the special-lock transfer.

### `SpecialLockTransfer.TransferOffset`

[in] The offset, in bytes, of the first page within the allocation that is transferred. This offset is applied only to a location that a segment location describes. This offset does not apply to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) description of a memory range. If the driver requires more than one paging buffer to complete the transfer (that is, the driver returns STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER from its [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function), **TransferOffset** is the same for each call to **DxgkDdiBuildPagingBuffer** for this transfer.

### `SpecialLockTransfer.TransferSize`

[in] The size, in bytes, of the memory information to transfer.

### `SpecialLockTransfer.Source`

[in] A structure that describes the source allocation. This structure contains a **SegmentId** member and a union that contains either an offset into a segment of the source allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the source (**pMdl**).

### `SpecialLockTransfer.Source.SegmentId`

[in] The identifier of a segment within the source allocation, or zero if the source allocation is described by the **pMdl** member of the union that **Source** contains.

#### SpecialLockTransfer.Source.(unnamed union)

[in] A union that contains either an offset into a segment of the source allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the source (**pMdl**).

### `SpecialLockTransfer.Source.SegmentAddress`

[in] The source segment address, if the **SegmentId** member of **Source** is nonzero. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `SpecialLockTransfer.Source.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the system memory pages for the source, if the **SegmentId** member of **Source** is zero.

### `SpecialLockTransfer.Destination`

[in] A structure that describes the destination allocation. This structure contains a **SegmentId** member and a union that contains either an offset into a segment of the destination allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the destination (**pMdl**).

### `SpecialLockTransfer.Destination.SegmentId`

[in] The identifier of a segment within the destination allocation, or zero if the destination allocation is described by the **pMdl** member of the union that **Destination** contains.

#### SpecialLockTransfer.Destination.(unnamed union)

[in] A union that contains either an offset into a segment of the destination allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the destination (**pMdl**).

### `SpecialLockTransfer.Destination.SegmentAddress`

[in] The destination segment address, if the **SegmentId** member of **Destination** is nonzero. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `SpecialLockTransfer.Destination.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the system memory pages for the destination, if the **SegmentId** member of **Destination** is zero.

### `SpecialLockTransfer.Flags`

[in] A [**DXGK_TRANSFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_transferflags) structure that identifies, in bit-field flags, the type of special-lock-transfer operation to perform.

### `SpecialLockTransfer.SwizzlingRangeId`

[in] A UINT value that identifies the swizzling range.

### `SpecialLockTransfer.SwizzlingRangeData`

[in] A UINT value that specifies swizzling range data.

### `InitContextResource`

[in] A structure that describes the context initialization operation. Supported beginning with Windows 8.

### `InitContextResource.hAllocation`

[in] A handle to the context allocation that was created when the driver called [**DxgkCbCreateContextAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation). The handle to this allocation is returned in the **hAllocation** member of the [**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure. The driver passes a pointer to this structure in the **ContextAllocation** parameter when it calls **DxgkCbCreateContextAllocation**.

### `InitContextResource.Destination`

[in] A structure that describes the destination context allocation. This structure contains a **SegmentId** member and a union that contains either an offset into a segment of the destination context allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the destination (**pMdl**).

### `InitContextResource.Destination.SegmentId`

[in] The identifier of a segment within the destination context allocation, or zero if the destination context allocation is described by the **pMdl** member of the union that **Destination** contains.

#### InitContextResource.Destination.(unnamed union)

[in] A union that contains either an offset into a segment of the destination context allocation (**SegmentAddress**) or a pointer to an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) for the destination (**pMdl**).

### `InitContextResource.Destination.SegmentAddress`

[in] The destination segment address, if the **SegmentId** member of **Destination** is nonzero. The DirectX graphics kernel subsystem computes the segment address as the sum of the segment offset and the base address of the segment: ```SegmentAddress = SegmentOffset + Segment.BaseAddr```.

### `InitContextResource.Destination.pMdl`

[in] A pointer to a buffer that contains the [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the system memory pages for the destination, if the **SegmentId** member of **Destination** is zero.

### `InitContextResource.Destination.VirtualAddress`

[in] The virtual address of the destination context allocation. This address is valid during the lifetime of the context allocation.

Follow procedures in the Virtual addresses for destination context allocations" section of the [**DxgkCbCreateContextAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) topic to ensure that the virtual address is valid.

### `InitContextResource.Destination.GpuVirtualAddress`

GPU virtual address of the context resource to initialize.

### `TransferVirtual`

A [**DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_transfervirtual) structure that describes the operation used to transfer allocation content between locations in memory.

### `FillVirtual`

A [**DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_fillvirtual) structure that describes the operation used to fill an allocation with a pattern.

### `UpdatePageTable`

A [**DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatepagetable) structure that describes the operation used to update a page table.

### `FlushTlb`

A [**DXGK_BUILDPAGINGBUFFER_FLUSHTLB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_flushtlb) structure that describes the operation used to flush the translation look-aside buffers.

### `CopyPageTableEntries`

A [**DXGK_BUILDPAGINGBUFFER_COPYPAGETABLEENTRIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_copypagetableentries) structure that describes the operation used copy page table entries from one location to another.

### `UpdateContextAllocation`

A [**DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatecontextallocation) structure that describes the operation used to update the content of a context or device allocation.

### `NotifyResidency`

A [**DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_notifyresidency) structure that describes a residency allocation change operation.

### `SignalMonitoredFence`

[in] A [**DXGK_BUILDPAGINGBUFFER_SIGNALMONITOREDFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_signalmonitoredfence) structure that describes a GPU instruction to signal the paging monitored fence object to the DMA buffer. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `MapApertureSegment2`

A structure that describes the map-aperture-segment operation using an ADL. See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

### `MapApertureSegment2.hDevice`

[in] A handle to the device that owns the allocation that **hAllocation** specifies that is mapped into the aperture segment that **SegmentId** specifies.

For a shared allocation, **hDevice** is set to the device that the video memory manager determined to be the owner of the allocation.

**hDevice** is **NULL** for the primary allocation.

### `MapApertureSegment2.hAllocation`

[in] The driver handle to the allocation that is mapped into the aperture segment that **SegmentId** specifies.

**hAllocation** is **NULL** when a DMA buffer is mapped into the aperture segment because DMA buffers are not explicitly created by the driver.

### `MapApertureSegment2.SegmentId`

[in] The identifier of an aperture segment to configure.

### `MapApertureSegment2.OffsetInPages`

[in] The offset, in pages, from the beginning of the segment to the first pages to map.

### `MapApertureSegment2.NumberOfPages`

[in] The size of the range being mapped within the allocation, in pages.

### `MapApertureSegment2.Adl`

[in] A [**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) structure with the address descriptor list (ADL) that describes the logical address mappings (pages) for the allocation memory. This ADL can be either contiguous or a page array; the driver must be able to handle both cases.

### `MapApertureSegment2.Flags`

[in] A [**DXGK_MAPAPERTUREFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_mapapertureflags) structure that identifies, in bit-field flags, the type of map-aperture-segment operation to perform.

### `MapApertureSegment2.AdlOffset`

[in] The offset within the [ADL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) to the start of the range of logical addresses being mapped for the current operation, specified in system memory pages. If the ADL is a contiguous ADL, then the ADL's **BasePageNumber** member is the start address of a contiguous range of memory. Otherwise use the ADL's **Pages** member for non-contiguous memory.

### `MapApertureSegment2.CpuVisibleAddress`

If a driver's allocation was created with the [**MapApertureCpuVisible**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags_wddm2_0) flag set, **CpuVisibleAddress** is a non-null pointer to a system-mapped, kernel-mode virtual address for [**DXGK_OPERATION_MAP_APERTURE_SEGMENT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) operations. This address is valid as long as the allocation is mapped into the aperture segment and will be freed immediately after the corresponding **DXGK_OPERATION_UNMAP_APERTURE_SEGMENT** call for the same allocation.

If **MapApertureCpuVisible** is not specified, **CpuVisibleAddress** is NULL for [**DXGK_OPERATION_MAP_APERTURE_SEGMENT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) operations.

### `Reserved`

This member is reserved and should not be used.

### `Reserved.Reserved`

This member is reserved and should not be used.

### `hSystemContext`

[in] A handle to the system context for the paging operation.

### `DmaBufferGpuVirtualAddress`

A **D3DGPU_VIRTUAL_ADDRESS** data type that indicates the virtual address where the DMA buffer was paged in. If the physical address is zero, the DMA buffer is not correctly paged in.

### `DmaBufferWriteOffset`

The current operation offset in bytes from the start of the DMA buffer.

## Remarks

MDL is defined in the [Windows Driver Model (WDM)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls) documentation.

WDDM synchronization class:

* [First Level GPU Scheduler Class](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-first-level) for [BuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) submission type.

## See also

[**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation)

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGK_BUILDPAGINGBUFFER_COPYPAGETABLEENTRIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_copypagetableentries)

[**DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_fillvirtual)

[**DXGK_BUILDPAGINGBUFFER_FLUSHTLB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_flushtlb)

[**DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_notifyresidency)

[**DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_transfervirtual)

[**DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatecontextallocation)

[**DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatepagetable)

[**DXGK_DISCARDCONTENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_discardcontentflags)

[**DXGK_MAPAPERTUREFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_mapapertureflags)

[**DXGK_TRANSFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_transferflags)

[**DxgkCbCreateContextAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[**MmGetMdlPfnArray**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetmdlpfnarray)

[**pfnLockCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)