# D3D12_FEATURE_DATA_VIDEO_PROCESS_MAX_INPUT_STREAMS structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_PROCESS\_MAX\_INPUT\_STREAMS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the maximum number of enabled input streams supported by the video processor.

## Members

### `NodeIndex`

An integer indicating which physical adapter of the device the operation applies to, in a multi-adapter operation.

### `MaxInputStreams`

The maximum number of streams that can be enabled for the video processor at the same time.

## Remarks

## See also