## Description

The **D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_0082_0** structure represents a group of pictures (GOP) definition for a video codec.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264GroupOfPictures`

Pointer to a [*D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_h264_0082_0) structure representing the GOP structure for H.264 encoding.

### `pHEVCGroupOfPictures`

Pointer to a [*D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_hevc_0082_0) structure representing the GOP structure for HEVC encoding.

### `pAV1SequenceStructure`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_SEQUENCE_STRUCTURE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_sequence_structure_0095) structure representing the GOP structure for AV1 encoding. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)