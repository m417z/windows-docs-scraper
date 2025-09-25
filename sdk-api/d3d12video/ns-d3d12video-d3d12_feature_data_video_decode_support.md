# D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves support information for video decoding.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [D3D12\_VIDEO\_DECODE\_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration) structure specifying the decode profile, bitstream encryption, and interlace type of the source stream.

### `Width`

The decode width of the source stream.

### `Height`

The decode height of the source stream

### `DecodeFormat`

The [DXGI\_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) to use as the decode format. This format is the output format if no decoder conversion is specified.

### `FrameRate`

The frame rate of the video format. A value of 0 means the frame rate is unknown.

### `BitRate`

The average bits per second data compression rate for the compressed video stream. This information is used by the driver to determine whether the video can be decoded in real-time. A value of 0 means the bit rate is unknown.

### `SupportFlags`

A combination of values from the [D3D12\_VIDEO\_DECODE\_SUPPORT\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_support_flags) enumeration indicating the support for video decoding. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `ConfigurationFlags`

A combination of values from the [D3D12\_VIDEO\_DECODE\_CONFIGURATION\_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_configuration_flags) enumeration describing the video decode configuration. This value is populated by the call to **ID3D12Device::CheckFeatureSupport**.

### `DecodeTier`

A member of the [D3D12\_VIDEO\_DECODE\_TIER](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) enumeration specifying the decoding tier of a hardware video decoder.

## Remarks

## See also