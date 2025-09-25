## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_HEAP_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified codec is supported for video encoding as well as the L0 and L1 sizes of the heap object.

## Members

### `HeapDesc`

A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc) structure specifying the creation properties for a video encoder heap. The driver should map these creation properties to size and assume the maximum resolution allowed for such heap.

### `IsSupported`

Receives a boolean value indicating if the encoder creation properties provided in **HeapDesc** are supported.

### `MemoryPoolL0Size`

Receives the L0 size of the heap object. Memory Pool L0 is the memory pool “closest” to the GPU. In the case of UMA adapters, this is the amount of system memory used. For discrete adapters, this is the amount of discrete memory used.

### `MemoryPoolL1Size`

Receives the L1 size of the heap object. Memory Pool L1 is the memory pool “second closest” to the GPU. In the case of UMA adapters, this value is zero. In the case of discrete adapters, this is the amount of system memory used.

## Remarks

## See also