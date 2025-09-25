## Description

The **D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0082_0** enumeration indicates which [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0) input configuration requests are *not* supported.

## Constants

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_NONE`

No flags (all configuration requests are supported).

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_CODEC_NOT_SUPPORTED`

The requested codec is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_INPUT_FORMAT_NOT_SUPPORTED`

The requested input format is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_CODEC_CONFIGURATION_NOT_SUPPORTED`

The requested codec configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_RATE_CONTROL_MODE_NOT_SUPPORTED`

The requested rate control mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_RATE_CONTROL_CONFIGURATION_NOT_SUPPORTED`

The requested rate control configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_INTRA_REFRESH_MODE_NOT_SUPPORTED`

The requested intra refresh mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_SUBREGION_LAYOUT_MODE_NOT_SUPPORTED`

The requested subregion layout mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_RESOLUTION_NOT_SUPPORTED_IN_LIST`

One of more of the requested resolutions in the list are not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0082_0_GOP_STRUCTURE_NOT_SUPPORTED`

The requested group of pictures (GOP) structure is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0095_SUBREGION_LAYOUT_DATA_NOT_SUPPORTED`

The requested subregion layout data is not supported.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)

[**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0)