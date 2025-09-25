# D3D12_FEATURE_DATA_VIDEO_PROCESS_REFERENCE_INFO structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_PROCESS\_REFERENCE\_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the number of past and future reference frames required for the specified deinterlace mode, filter, rate conversion, or auto processing features.

## Members

### `NodeIndex`

An integer indicating which physical adapter of the device the operation applies to, in a multi-adapter operation.

### `DeinterlaceMode`

A member of the [D3D12\_VIDEO\_PROCESS\_DEINTERLACE\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_deinterlace_flags) enumeration specifying the deinterlacing mode for which the required past and future reference frame counts are retrieved.

### `Filters`

A bitwise OR combination of values from the [D3D12\_VIDEO\_PROCESS\_FILTER\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_filter_flags) enumeration specifying the filters for which the required past and future reference frame counts are retrieved.

### `FeatureSupport`

A bitwise OR combination of values from the [D3D12\_VIDEO\_PROCESS\_FEATURE\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_feature_flags) enumeration specifying the features for which the required past and future reference frame counts are retrieved.

### `InputFrameRate`

The input frame rate of the stream for which the required past and future reference frame counts are retrieved.

### `OutputFrameRate`

The output frame rate of the stream for which the required past and future reference frame counts are retrieved.

### `EnableAutoProcessing`

True if autoprocessing will be used; otherwise, false.

### `PastFrames`

The number of past frames required to support the specified processing features.

### `FutureFrames`

The number of future frames required to support the specified processing features.

## Remarks

## See also