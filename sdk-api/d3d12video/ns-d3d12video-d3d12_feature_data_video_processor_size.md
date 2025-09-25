## Description

Describes the allocation size of a video decoder heap.

## Members

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `pOutputStreamDesc`

A pointer to a D3D12\_VIDEO\_PROCESS\_OUTPUT\_STREAM\_DESC(ns-d3d12video-d3d12_video_process_output_stream_desc) structure describing the output stream.

### `NumInputStreamDescs`

The number of input streams provided in the *pInputStreamDescs* parameter.

### `pInputStreamDescs`

A pointer to a list of D3D12\_VIDEO\_PROCESS\_INPUT\_STREAM\_DESC(ns-d3d12video-d3d12_video_process_input_stream_desc) structures the input streams.

### `MemoryPoolL0Size`

The allocation size of the video processor in the L0 memory pool. L0 is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one which is valid. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MemoryPoolL1Size`

The allocation size of the video processor in the L1 memory pool. L1 is typically known as the physical video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

## Remarks

## See also

[Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency)