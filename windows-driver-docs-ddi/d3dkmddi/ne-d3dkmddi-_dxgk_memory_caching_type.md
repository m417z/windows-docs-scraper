# DXGK_MEMORY_CACHING_TYPE enumeration

## Description

**DXGK_MEMORY_CACHING_TYPE** describes the memory caching types during allocation.

## Constants

### `DXGK_MEMORY_CACHING_TYPE_NON_CACHED`

The memory is not cached.

### `DXGK_MEMORY_CACHING_TYPE_CACHED`

The memory is cached.

### `DXGK_MEMORY_CACHING_TYPE_WRITE_COMBINED`

The memory caching type is write combined.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatecontiguousmemory)