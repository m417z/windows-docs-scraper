# DXGI_MEMORY_SEGMENT_GROUP enumeration

## Description

Specifies the memory segment group to use.

## Constants

### `DXGI_MEMORY_SEGMENT_GROUP_LOCAL:0`

 The grouping of segments which is considered local to the video adapter, and represents the fastest available memory to the GPU. Applications should target the local segment group as the target size for their working set.

### `DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL:1`

The grouping of segments which is considered non-local to the video adapter, and may have slower performance than the local segment group.

## Remarks

This enum is used by [QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo) and [SetVideoMemoryReservation](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-setvideomemoryreservation).

Refer to the remarks for [D3D12_MEMORY_POOL](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool).

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)