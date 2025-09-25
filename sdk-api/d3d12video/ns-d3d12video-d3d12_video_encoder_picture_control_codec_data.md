## Description

Represents the picture level control elements for the associated [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) command for multiple codecs.

## Members

### `DataSize`

The data size of the provided picture level control structure.

### `pH264PicData`

A pointer to a [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264) representing the picture level control elements for H.264 encoding.

### `pHEVCPicData`

A pointer to a [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reference_picture_descriptor_hevc) representing the picture level control elements for H.264 encoding.

## Remarks

Slice-level picture reference lists reordering is unsupported.

Weighted inter-prediction is unsupported.

## See also