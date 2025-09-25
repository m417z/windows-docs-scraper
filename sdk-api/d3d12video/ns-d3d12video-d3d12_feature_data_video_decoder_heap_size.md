## Description

Describes the allocation size of a video decoder heap.

## Members

### `VideoDecoderHeapDesc`

A [D3D12_VIDEO_DECODER_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decoder_heap_desc) describing a [ID3D12VideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap).

### `MemoryPoolL0Size`

The allocation size of the video decoder heap in the L0 memory pool. L0 is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one which is valid. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MemoryPoolL1Size`

The allocation size of the video decoder heap in the L1 memory pool. L1 is typically known as the physical video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

## Remarks

## See also

[Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency)