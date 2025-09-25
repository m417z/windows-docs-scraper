# D3D12_VIDEO_PROCESS_REFERENCE_SET structure

## Description

Contains the reference frames needed to perform video processing.

## Members

### `NumPastFrames`

The number of past reference frames provided in *ppPastFrames*.

### `ppPastFrames`

A pointer to an array of [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) surfaces. The number of elements in the array is *NumPastFrames*.

### `pPastSubresources`

An array of subresource indices for the list of *ppPastFrames* textures. NULL indicates subresource 0 for each resource.

### `NumFutureFrames`

The number of future reference frames provided in *ppPastFrames*.

### `ppFutureFrames`

A pointer to an array of [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) surfaces. The number of elements in the array is *NumFutureFrames*.

### `pFutureSubresources`

An array of subresource indices for the list of *ppFutureFrames* textures. NULL indicates subresource 0 for each resource.

## Remarks

## See also

[D3D12_FEATURE_VIDEO_PROCESS_REFERENCE_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video)