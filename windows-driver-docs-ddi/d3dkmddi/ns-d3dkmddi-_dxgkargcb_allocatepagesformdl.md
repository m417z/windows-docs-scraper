# DXGKARGCB_ALLOCATEPAGESFORMDL structure

## Description

The **DXGKARGCB_ALLOCATEPAGESFORMDL** structure contains the arguments used in the [**DXGKCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatepagesformdl) callback function, to allocate pages for a memory descriptor list (MDL).

## Members

### `LowAddress` [in]

Specifies the physical address of the start of the first address range from which the allocated pages can come.

### `HighAddress` [in]

Specifies the physical address of the end of the first address range from which the allocated pages can come.

### `SkipBytes` [in]

Specifies the number of bytes to skip from the start of the previous address range from which the allocated pages can come. SkipBytes must be an integer multiple of the virtual memory page size, in bytes.

### `TotalBytes` [in]

Specifies the total number of bytes to allocate for the MDL.

### `CacheType` [in]

Indicates the type of caching that is allowed for the requested memory.

### `Flags` [in]

Specifies the flags for this operation. For more information, see [MmAllocatePagesForMdlEx function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex).

### `hMemoryHandle` [out]

A *Dxgkrnl* tracking handle for the allocation. This value should be passed to the corresponding [**DGXKCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freepagesfrommdl) callback function.

### `pMdl` [out]

An MDL of non-paged memory guaranteed to be mapped to the IOMMU for its lifetime.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatepagesformdl)