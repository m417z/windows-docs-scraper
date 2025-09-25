## Description

The **D3D12DDICAPS_VIDEO_ENCODER_HEAP_SIZE_DATA_0080_2** structure is used to retrieve the memory requirements of a video encoder heap.

## Members

### `HeapDesc`

[in] A [**D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_heap_0080_2) structure that specifies the creation properties for a video encoder heap. The driver should map these creation properties to size and assume the maximum resolution allowed for such a heap.

### `IsSupported`

[out] Indicates whether the given feature values are supported.

### `MemoryPoolL0Size`

[out] The L0 size of the heap object, in bytes. Memory pool L0 is the memory pool "closest" to the GPU. For UMA adapters, this is the amount of system memory used. For discrete adapters, this is the amount of discrete memory used.

### `MemoryPoolL1Size`

[out] The L1 size of the heap object, in bytes. Memory pool L0 is the memory pool "second closest" to the GPU. For UMA adapters, this value is zero. For discrete adapters, this is the amount of system memory used.

## Remarks

The D3D runtime calls [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with [**D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_HEAP_SIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) specified as the capability type.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)