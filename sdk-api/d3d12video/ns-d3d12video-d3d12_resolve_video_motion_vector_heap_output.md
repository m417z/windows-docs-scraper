## Description

Receives output data from calls to [ID3D12VideoEncodeCommandList::ResolveMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-resolvemotionvectorheap).

## Members

### `pMotionVectorTexture2D`

An [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) representing the output resource for resolved motion vectors. Motion vectors are resolved to [DXGI_FORMAT_R16G16_SINT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) 2D textures. The resolved data is a signed 16-byte integer with quarter PEL units with the X vector component stored in the R component and the Y vector component stored in the G component. Motion vectors are stored in a 2D layout that corresponds to the pixel layout of the original input textures.

### `MotionVectorCoordinate`

A [D3D12_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_resource_coordinate) structure specifying the output origin of the motion vectors. The remaining sub-region must be large enough to store all motion vectors per block specified by the input pixel with and pixel height and the specified [D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_search_block_size).

## Remarks

## See also