# D3D12_FEATURE_DATA_VIDEO_PROCESS_SUPPORT structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_PROCESS\_SUPPORT ](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## Members

### `NodeIndex`

An integer indicating which physical adapter of the device the operation applies to, in a multi-adapter operation.

### `InputSample`

A [D3D12\_VIDEO\_SAMPLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_sample) structure defining the width, height, and format of the input sample.

### `InputFieldType`

A member of the [D3D12\_VIDEO\_FIELD\_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_field_type) enumeration specifying the interlaced field type of the input sample.

### `InputStereoFormat`

A member of the [D3D12\_VIDEO\_FRAME\_STEREO\_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_stereo_format) enumeration specifying the stereo format of the input sample.

### `InputFrameRate`

The input frame rate.

### `OutputFormat`

A [D3D12\_VIDEO\_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_format) structure specifying the output DXGI format and color space.

### `OutputStereoFormat`

A member of the [D3D12\_VIDEO\_FRAME\_STEREO\_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_stereo_format) enumeration specifying the stereo format of the output.

### `OutputFrameRate`

The output frame rate.

### `SupportFlags`

A member of the [D3D12\_VIDEO\_PROCESS\_SUPPORT\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_support_flags) indicating whether the requested format and colorspace conversion is supported. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `ScaleSupport`

A [D3D12\_VIDEO\_SCALE\_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_scale_support) structure specifying the supported scaling capabilities. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `FeatureSupport`

A bitwise OR combination of values from the [D3D12\_VIDEO\_PROCESS\_FEATURE\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_feature_flags) enumeration specifying the supported video processing features. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `DeinterlaceSupport`

A member of the [D3D12\_VIDEO\_PROCESS\_DEINTERLACE\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_deinterlace_flags) enumeration specifying the supported deinterlacing capabilities. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `AutoProcessingSupport`

A member of the [D3D12\_VIDEO\_PROCESS\_AUTO\_PROCESSING\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_auto_processing_flags) specifying the supported automatic processing capabilities. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `FilterSupport`

A bitwise OR combination of values from the [D3D12\_VIDEO\_PROCESS\_FILTER\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_filter_flags) enumeration specifying the supported video filtering features. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `FilterRangeSupport`

An array of [D3D12\_VIDEO\_PROCESS\_FILTER\_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_filter_range) structures representing the filter range values. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**. The calling application must allocate the memory for the filter range list before calling **CheckFeatureSupport**.

## Remarks

## See also