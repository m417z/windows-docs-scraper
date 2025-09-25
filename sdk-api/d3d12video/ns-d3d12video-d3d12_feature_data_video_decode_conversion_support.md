# D3D12_FEATURE_DATA_VIDEO_DECODE_CONVERSION_SUPPORT structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_CONVERSION\_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of supported profiles. Check if a colorspace conversion, format conversion, and scale are supported.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [D3D12\_VIDEO\_DECODE\_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration) structure describing the decode configuration.

### `DecodeSample`

A [D3D12\_VIDEO\_SAMPLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_sample) structure representing the source decoded as sample description.

### `OutputFormat`

A [D3D12\_VIDEO\_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_format) structure containing the output sample description.

### `FrameRate`

The frame rate of the video content. This is used by the driver to determine whether the video can be decoded in real-time.

### `BitRate`

The average bits per second data compression rate for the compressed video stream. This is used by the driver to determine whether the video can be decoded in real-time.

### `SupportFlags`

A combination of values from the [D3D12\_VIDEO\_DECODE\_CONVERSION\_SUPPORT\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_conversion_support_flags) indicating the support for the specified conversion.

### `ScaleSupport`

A [D3D12\_VIDEO\_SCALE\_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_scale_support) structure representing the output size range for decode conversion.

## Remarks

If the colorspace and format conversion is supported, *ScaleFlags* will have the [D3D12\_VIDEO\_SCALE\_SUPPORT\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_scale_support_flags) set. Callers should check the [D3D12\_VIDEO\_SIZE\_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) field to determine if the requested scale is supported.

## See also

[D3D12_FEATURE_VIDEO_DECODE_CONVERSION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video)