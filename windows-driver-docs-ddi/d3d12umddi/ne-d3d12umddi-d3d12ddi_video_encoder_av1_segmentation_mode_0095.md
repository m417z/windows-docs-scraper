## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095** enumeration defines the distinct segmentation modes that can be used for the segmentation map in the AV1 video encoding process.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_DISABLED:0`

Indicates that the use of segmentation is disabled.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_Q:1`

Indicates that alternative quantization parameters within segments can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_LF_Y_V:2`

Indicates that alternative lvertical oop filter strengths for the luma (Y) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_LF_Y_H:3`

Indicates that alternative horizontal loop filter strengths for the luma (Y) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_LF_U:4`

Indicates that alternative loop filter strengths for the chroma (U) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_LF_V:5`

Indicates that alternative loop filter strengths for the chroma (V) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_REF_FRAME:6`

Indicates that alternative reference frame selection can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_SKIP:7`

Indicates whether certain segments should be skipped (i.e., encoded using inter prediction modes only).

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_ALT_GLOBALMV:8`

Indicates that alternative global motion vector parameters can be used.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_config_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_mode_0095_flags)

[**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095)