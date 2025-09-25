## Description

Specifies video encoder rate control modes.

## Constants

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_ABSOLUTE_QP_MAP`

No rate control budgeting. Each [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) call will interpret the the QP values in the **pRateControlQPMap** field of the [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264) or [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_hevc) structure as a map of absolute QP values.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_CQP`

Constant quantization parameter rate control mode.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_CBR`

Constant bit rate rate control mode.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_VBR`

Variable bit rate control mode.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_QVBR`

Constant quality target rate variable rate control mode.

## Remarks

## See also

[EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe)

[D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264)

[D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_hevc)