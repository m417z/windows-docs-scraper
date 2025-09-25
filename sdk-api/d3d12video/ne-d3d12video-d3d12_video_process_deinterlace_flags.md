# D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS enumeration

## Description

Specifies the deinterlacing video processor capabilities.

## Constants

### `D3D12_VIDEO_PROCESS_DEINTERLACE_FLAG_NONE`

No deinterlacing capabilities are available.

### `D3D12_VIDEO_PROCESS_DEINTERLACE_FLAG_BOB`

The video processor can perform bob deinterlacing. In bob deinterlacing, missing field lines are interpolated from the lines above and below. Bob deinterlacing does not require reference frames.

### `D3D12_VIDEO_PROCESS_DEINTERLACE_FLAG_CUSTOM`

The video processor can perform a custom high-quality deinterlacing, which requires the number of reference frames indicated in *PastFrames* and *FutureFrames* output fields of the [D3D12_FEATURE_DATA_VIDEO_PROCESS_REFERENCE_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_process_reference_info) populated by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_PROCESS_REFERENCE_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). If the video processor doesn’t have the necessary number of reference frames, it falls back to bob deinterlacing.

## Remarks

## See also