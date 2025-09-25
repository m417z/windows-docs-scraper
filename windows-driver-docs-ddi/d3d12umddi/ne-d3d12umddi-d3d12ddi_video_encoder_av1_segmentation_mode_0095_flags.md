## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAGS** enumeration defines the supported segmentation modes that can be used for the segmentation map in the AV1 video encoding process.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_NONE`

Indicates that no segmentation flags are set.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_DISABLED`

Indicates that the use of segmentation is disabled.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_Q`

Indicates that alternative quantization parameters within segments can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_LF_Y_V`

Indicates that alternative vertical loop filter strengths for the luma (Y) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_LF_Y_H`

Indicates that alternative horizontal loop filter strengths for the luma (Y) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_LF_U`

Indicates that alternative loop filter strengths for the chroma (U) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_LF_V`

Indicates that alternative loop filter strengths for the chroma (V) component can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_REF_FRAME`

Indicates that alternative reference frames can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_SKIP`

Indicates that alternative skip flags can be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAG_ALT_GLOBALMV`

Indicates that alternative global motion vector parameters can be used.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_config_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_mode_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095)