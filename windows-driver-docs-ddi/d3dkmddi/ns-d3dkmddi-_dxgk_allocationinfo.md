# DXGK_ALLOCATIONINFO structure

## Description

The **DXGK_ALLOCATIONINFO** structure describes parameters for creating an allocation.

## Members

### `pPrivateDriverData`

[in] A pointer to a block of private data. This data is for each allocation and is distinct from the **pPrivateDriverData** member in the [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure. The user-mode display driver (UMD) might pass this data to the kernel-mode display miniport driver (KMD). However, if *Dxgkrnl* passes this data to describe the shared primary or other lockable surface, the data is passed as the first element of the array in the **pAllocationInfo** member of **DXGKARG_CREATEALLOCATION**.

### `PrivateDriverDataSize`

[in] The size, in bytes, of the block of private data in **pPrivateDriverData**.

### `Alignment`

[out] The required alignment, in bytes, for the allocation.

### `Size`

[out] The size, in bytes, that is required for the allocation. The size value is expanded to a multiple of the native host page size (for example, 4 KB on the x86 architecture). The KMD specifies the allocation size to the video memory manager (*VidMm*).

### `PitchAlignedSize`

[out] The size, in bytes, of the allocation when it is located in a pitch-aligned segment, which is specified by the **PitchAlignment** bit-field flag in the **Flags** member of the [**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor) structure for the segment. If the allocation is not supported in a pitch-aligned segment (GPUs don't commonly support this type of segment), the driver should set the value in **PitchAlignedSize** to zero. If the driver specifies a nonzero value in **PitchAlignedSize**, the value must be greater than or equal to the value in the **Size** member.

### `HintedBank`

[out] A [**DXGK_SEGMENTBANKPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentbankpreference) structure that specifies KMD's bank ordering preferences that *VidMm* use to page-in the allocation. If this member is specified, *VidMm* uses banking information about the most preferred segment, which is specified by the **SegmentId0** member of the [**DXGK_SEGMENTPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_segmentpreference) structure that the **PreferredSegment** member specifies.

### `PreferredSegment`

[out] A [**DXGK_SEGMENTPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_segmentpreference) structure that indicates preferred segments identifiers that the KMD requests that *VidMm* use to page-in the allocation.

### `SupportedReadSegmentSet`

[out] Segment identifiers that the KMD can set in the **PreferredSegment** member for read operations. The segments that these identifiers indicate are segments that the KMD requests *VidMm* use to page-in the allocation for read operations, regardless of performance. Setting bit 0 indicates that the first segment is supported, setting bit 1 indicates that the second segment is supported, and so on.

The KMD can set preferences only for segments that are supported for read operations. *VidMm* asserts if the driver attempts to set preferences for unsupported segments in the **PreferredSegment** member.

### `SupportedWriteSegmentSet`

[out] Segment identifiers that the KMD can set in the **PreferredSegment** member for write operations. The segments that these identifiers indicate are segments that the KMD requests that *VidMm* use to page-in the allocation for write operations, regardless of performance. Setting bit 0 indicates that the first segment is supported, setting bit 1 indicates that the second segment is supported, and so on.

The KMD can set preferences only for segments that are supported for write operations. *VidMm* asserts if the driver attempts to set preferences for unsupported segments in the **PreferredSegment** member.

### `EvictionSegmentSet`

[out] Identifiers of segments that can be used for eviction. Setting bit 0 indicates that the first segment can be used for eviction, setting bit 1 indicates that the second segment can be used for eviction, and so on.

Only aperture segments can be specified by this member. If the driver specifies valid segments to be used for eviction, *VidMm* attempts to allocate resources in those aperture segments to accelerate the eviction process. If the driver specifies 0, *VidMm* calls the driver to transfer the content of an allocation directly to paged-locked system memory without mapping the underlying pages through an aperture segment.

### `MaximumRenamingListLength`

[out] The maximum length of the renaming list for the allocation. For more information about the renaming list, see [Requesting to Rename an Allocation](https://learn.microsoft.com/windows-hardware/drivers/display/requesting-to-rename-an-allocation).

Support for this member started with Windows 10 and the WDDM v2.

### `PhysicalAdapterIndex`

[out] The index of the physical adapter.

Support for this member started with Windows 10 and the WDDM v2.

### `hAllocation`

[out] A handle to the allocation. The KMD must set this member to a value that it can use to refer to its private tracking structure for the allocation.

### `Flags`

[out] A [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags) structure that identifies properties for an allocation in bit-field flags. These properties indicate the type of allocation to create. The KMD specifies these flags for *VidMm*. Drivers that target any WDDM version earlier than WDDM 2.0 should use **Flags**; drivers that target any WDDM version >= WDDM 2.0 should use **FlagsWddm2**.

### `FlagsWddm2`

[out] A [**DXGK_ALLOCATIONINFOFLAGS_WDDM2_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags_wddm2_0) structure that identifies properties for an allocation in bit-field flags. These properties indicate the type of allocation to create. The KMD specifies these flags for *VidMm*. Drivers that target any WDDM version >= WDDM 2.0 should use **FlagsWddm2**; drivers that target any WDDM version earlier than WDDM 2.0 should use **Flags**.

### `pAllocationUsageHint`

[out] A pointer to a [**DXGK_ALLOCATIONUSAGEHINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationusagehint) structure that the memory manager uses to determine how to use the allocation.

### `AllocationPriority`

[out] A UINT value that specifies the starting priority level of the allocation.

The driver determines the appropriate priority level for each allocation. For more information about priority levels, see the Remarks section of the [**pfnSetPriorityCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) function. If priority level for allocations is not an issue to the driver, the driver should set all priority levels to **D3DDDI_ALLOCATIONPRIORITY_NORMAL**. Note that 0 is an invalid initial allocation priority.

### `Flags2`

[out] A [**DXGK_ALLOCATIONINFOFLAGS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_allocationinfoflags2) structure that contains additional properties for an allocation. Supported starting in Windows 11 (WDDM 3.0).

## Remarks

With the WDDM v2, the **DXGK_ALLOCATIONINFO** structure has been changed so that the read and write segment set are no longer differentiated. During surface creation, *VidMm* will ignore the **SupportedReadSegmentSet** value and use only the segment set provide by **SupportedWriteSegmentSet**. Drivers should ensure that this value accurately represents the segment set that can be used by the allocation for its intended purpose.

Ignoring the supported read segment set doesn't mean that it is no longer supported, but simply that there should no longer be a difference between these sets, and *VidMm* will be allowed to choose an appropriate segment for any allocation from a single segment set.

## See also

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)

[**DXGK_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[**DXGK_ALLOCATIONUSAGEHINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationusagehint)

[**DXGK_SEGMENTBANKPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentbankpreference)

[**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor)

[**DXGK_SEGMENTPREFERENCE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562047(v=vs.85))

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)