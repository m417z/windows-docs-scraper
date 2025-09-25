## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0** structure contains picture control codec-specific data.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264PicData`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0) structure containing the picture-level control data for H.264 encoding.

### `pHEVCPicData`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_hevc_0082_0) structure containing the picture-level control data for HEVC encoding.

### `pAV1PicData`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095) structure containing the picture-level control data for AV1 encoding. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

Slice-level picture reference lists reordering is not supported.

Weighted inter-prediction is not supported.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0)