## Description

Gets the resolution list associated with the video encoder heap.

## Parameters

### `ResolutionsListCount`

The count of resolutions to retrieve. Get the number of resolutions with which the encoder heap was created by calling [ID3D12VideoEncoderHeap::GetResolutionListCount](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencoderheap-getresolutionlistcount).

### `pResolutionList`

Receives a pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) structures representing the resolutions specified in the [D3D12_VIDEO_ENCODER_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc) passed into [ID3D12VideoDevice3::CreateVideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice3-createvideoencoderheap).

## Return value

Returns S_OK on success.

## Remarks

## See also