# D3D12_FEATURE_DATA_VIDEO_DECODE_FORMATS structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of supported formats.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [D3D12\_VIDEO\_DECODE\_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration) structure describing the decode configuration for the list of formats.

### `FormatCount`

The number of formats to retrieve. This number must match the value returned from a call [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_FORMAT\_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

### `pOutputFormats`

A list of [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structures representing the supported formats.

## Remarks

## See also