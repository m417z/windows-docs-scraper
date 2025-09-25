## Description

The **D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095** structure describes support for the video encoder frame subregion layout configuration, particularly for the AV1 codec.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) enumeration that represents the desired codec to check support for.

### `Profile`

[in] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_02**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that describes the desired profile to check support for.

### `Level`

[in] A [**D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_level_setting_0080_2) structure that describes the desired level to check support for.

### `SubregionMode`

[in] A [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080) enumeration that specifies the desired frame subregion layout mode to check support for.

### `FrameResolution`

[in] A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure that describes the desired resolution to check support for.

### `CodecSupport`

[in/out] A [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_config_support_0095) structure that describes the codec-specific support for this capability.

### `IsSupported`

[out] A Boolean value that indicates whether the driver supports this subregion layout configuration based on the input values, including the codec, profile, level, resolution and any other codec specific parameters.

## Remarks

Currently, this support query is only supported for **Codec** set to D3D12DDI_VIDEO_ENCODER_CODEC_0095_AV1, as it can only be compiled with a **CodecSupport.pAV1Support** pointer of type [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_frame_subregion_layout_config_support_0095).

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.