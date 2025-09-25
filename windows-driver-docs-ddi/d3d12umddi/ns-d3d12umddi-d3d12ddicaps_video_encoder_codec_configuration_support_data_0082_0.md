## Description

The **D3D12DDICAPS_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_DATA_0082_0** structure is used to indicate whether the specified input HEVC codec configuration parameters are supported or retrieves (outputs) the supported configuration for H.264 encoding.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the codec to check support for.

### `Profile`

[in] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that specifies the profile to check support for.

### `IsSupported`

[out] Indicates whether the given feature values are supported.

### `CodecSupportLimits`

[in/out] A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_0082_0) structure:

* For H.264 encoding, this structure is used as an output parameter in which the driver writes the support configuration limits.
* For HEVC encoding, this structure contains input parameters with the user-requested HEVC configuration.

## Remarks

Use [**D3D12DDICAPS_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_codec_configuration_support_data_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## See also

[**D3D12DDICAPS_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_codec_configuration_support_data_0083_0)