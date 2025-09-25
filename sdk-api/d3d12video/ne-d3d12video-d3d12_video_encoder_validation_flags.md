## Description

Specifies flags returned in the *ValidationFlags* field of the [D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_support) structure passed into a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). The returned flags indicate the features that are not supported.

## Constants

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_CODEC_NOT_SUPPORTED`

The specified codec is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_INPUT_FORMAT_NOT_SUPPORTED`

The specified input format is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_CODEC_CONFIGURATION_NOT_SUPPORTED`

The specified codec configuration is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_RATE_CONTROL_MODE_NOT_SUPPORTED`

The specified rate control mode is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_RATE_CONTROL_CONFIGURATION_NOT_SUPPORTED`

The specified rate control configuration is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_INTRA_REFRESH_MODE_NOT_SUPPORTED`

The specified intra refresh mode is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_SUBREGION_LAYOUT_MODE_NOT_SUPPORTED`

The specified subregion layout mode is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_RESOLUTION_NOT_SUPPORTED_IN_LIST`

The specified resolution is not supported.

### `D3D12_VIDEO_ENCODER_VALIDATION_FLAG_GOP_STRUCTURE_NOT_SUPPORTED`

The specified GOP structure is not supported.

## Remarks

## See also