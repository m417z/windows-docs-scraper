## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_INPUT_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified codec, profile, and format are supported for video encoding.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which support is being queried.

### `Profile`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the profile for which support is being queried.

### `Format`

A member of the [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration specifying the pixel format for which support is being queried. This format definition includes the subsampling and bit-depth modes settings for the video encoding session.

To query encoder support for 4:2:0 with 8 and 10 bitdepth samples using following values for the **Format** field:
- DXGI_FORMAT_P010
- DXGI_FORMAT_NV12

> [!NOTE]
> The host is expected to handle the input subsampling and color conversion stages of video encoding.

### `IsSupported`

Receives a boolean value indicating if the specified codec, profile, and format are supported.

## Remarks

## See also