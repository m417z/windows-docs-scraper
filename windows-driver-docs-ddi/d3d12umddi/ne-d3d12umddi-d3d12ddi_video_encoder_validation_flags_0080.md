## Description

The **D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0080** enumeration indicates which [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0) input configuration requests are *not* supported. Use [**D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_validation_flags_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## Constants

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_NONE:0x0`

No flags (all configuration requests are supported).

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_CODEC_NOT_SUPPORTED:0x1`

The requested codec is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_PROFILE_NOT_SUPPORTED:0x2`

The requested profile is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_LEVEL_NOT_SUPPORTED:0x4`

The requested level is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_INPUT_FORMAT_NOT_SUPPORTED:0x8`

The requested input format is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_CODEC_CONFIGURATION_NOT_SUPPORTED:0x10`

The requested codec configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_RATE_CONTROL_MODE_NOT_SUPPORTED:0x20`

The requested rate control mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_RATE_CONTROL_CONFIGURATION_NOT_SUPPORTED:0x40`

The requested rate control configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_INTRA_REFRESH_MODE_NOT_SUPPORTED:0x80`

The requested intra refresh mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_SUBREGION_LAYOUT_MODE_NOT_SUPPORTED:0x100`

The requested subregion layout mode is not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_RESOLUTION_NOT_SUPPORTED_IN_LIST:0x200`

One of more of the requested resolutions in the list are not supported.

### `D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0080_SUGGESTED_TARGET_PROFILE_OR_LEVEL_MISMATCH:0x400`

The suggested profile or level doesn't match.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_validation_flags_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).