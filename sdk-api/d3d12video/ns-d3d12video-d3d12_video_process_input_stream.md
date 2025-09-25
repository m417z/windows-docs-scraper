# D3D12_VIDEO_PROCESS_INPUT_STREAM structure

## Description

Contains input information for the video processor blend functionality.

## Members

### `pTexture2D`

An [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the current input field or frame.

### `Subresource`

The subresource index to use of the *pTexture2D* argument.

### `ReferenceSet`

A [D3D12_VIDEO_PROCESS_REFERENCE_SET](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_reference_set) containing the set of references for video processing. Some video processing algorithms require forward or backward frame references. For more information, see [D3D12_FEATURE_VIDEO_PROCESS_REFERENCE_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## Remarks

## See also