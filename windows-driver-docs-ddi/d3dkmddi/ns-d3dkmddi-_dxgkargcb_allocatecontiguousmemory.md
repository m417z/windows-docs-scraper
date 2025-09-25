# DXGKARGCB_ALLOCATECONTIGUOUSMEMORY structure

## Description

The **DXGKARGCB_ALLOCATECONTIGUOUSMEMORY** structure contains the arguments used in the [**DXGKCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatecontiguousmemory) callback function, to allocate contiguous memory.

## Members

### `NumberOfBytes` [in]

The size, in bytes, of the block of contiguous memory to allocate.

### `LowestAcceptableAddress` [in]

The lowest valid physical address the caller can use. For example, if a device can address only locations above the first 8 megabytes of the processor's physical memory address range, the driver for this device should set LowestAcceptableAddress to 0x0000000000800000.

### `HighestAcceptableAddress` [in]

The highest valid physical address the caller can use. For example, if a device can address only locations in the first 16 megabytes of the processor's physical memory address range, the driver for this device should set HighestAcceptableAddress to 0x0000000000FFFFFF.

### `BoundaryAddressMultiple` [in]

The physical address multiple that the allocated buffer must not cross. A physical address multiple must always be a power of two. This parameter is optional and can be specified as zero to indicate that the device has no special memory boundary restrictions.

### `CacheType` [in]

A [**DXGK_MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_memory_caching_type) value that specifies the cache type of the pages to allocate.

### `hMemoryHandle` [out]

A *Dxgkrnl* tracking handle for the allocation. This value should be passed to the corresponding [**DGXKCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freecontiguousmemory) callback function.

### `pMemory` [out]

A contiguous chunk of non-paged physical memory guaranteed to be mapped to the IOMMU for its lifetime.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatecontiguousmemory)