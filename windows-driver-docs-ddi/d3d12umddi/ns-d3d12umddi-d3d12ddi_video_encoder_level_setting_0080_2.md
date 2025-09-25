## Description

The **D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2** structure encapsulates a generic level-related setting definition.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264LevelSetting`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_LEVELS_H264_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_levels_h264_0080) value that identifies the H.264 level.

### `pHEVCLevelSetting`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_LEVEL_TIER_CONSTRAINTS_HEVC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_level_tier_constraints_hevc_0080) structure that identifies the level and tier for an HVEC level configuration.

### `pAV1LevelSetting`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_LEVEL_TIER_CONSTRAINTS_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_level_tier_constraints_0095) structure that identifies the level and tier for an AV1 level configuration. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_heap_0080_2)