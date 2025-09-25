## Description

**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2** is a generic structure for codec profiles.

## Members

### `DataSize`

The size of the referenced data, in bytes.

### `pH264Profile`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PROFILE_H264_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_profile_h264_0080) value that indicates an H.264 profile.

### `pHEVCProfile`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PROFILE_HEVC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_profile_hevc_0080) value that indicates an HEVC profile.

### `pAV1Profile`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_PROFILE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_profile_0095) value that indicates an AV1 profile. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information, including an explanation about the pointers to enum types.

## See also

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_0082_0)