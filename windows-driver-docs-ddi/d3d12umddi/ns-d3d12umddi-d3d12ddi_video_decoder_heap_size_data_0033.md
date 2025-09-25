# D3D12DDI_VIDEO_DECODER_HEAP_SIZE_DATA_0033 structure

## Description

Retrieves the memory allocation size of a video decoder heap created with the given properties. This structure is for the D3D12DDICAPS_TYPE_VIDEO_0032_DECODER_HEAP_SIZE capability check in [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

## Members

### `VideoDecoderHeapDesc`

The creation properties for a video decoder heap. Driver should map these creation properties to size.

### `MemoryPoolL0Size`

The L0 size of the heap object. Memory Pool L0 is the memory pool “closest” to the GPU. In the case of UMA adapters, this is the amount of system memory used. For discrete adapters, this is the amount of discrete memory used.

### `MemoryPoolL1Size`

The L1 size of the heap object. Memory Pool L1 is the memory pool “second closest” to the GPU. In the case of UMA adapters, this value is zero. In the case of discrete adapters, this is the amount of system memory used.