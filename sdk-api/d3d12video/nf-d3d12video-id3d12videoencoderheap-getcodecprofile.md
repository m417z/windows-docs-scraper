## Description

Gets the codec profile associated with the video encoder heap.

## Parameters

### `dstProfile`

Receives a [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure representing the codec profile specified in the [D3D12_VIDEO_ENCODER_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc) passed into [ID3D12VideoDevice3::CreateVideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice3-createvideoencoderheap).

## Return value

Returns S_OK on success.

## Remarks

## See also