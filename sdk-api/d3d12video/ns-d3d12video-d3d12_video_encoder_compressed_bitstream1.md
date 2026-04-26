## Description

Encapsulates the compressed bitstream output for an encoding operation, with support for subregion notification.

## Members

### `NotificationMode`

A [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM_NOTIFICATION_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_compressed_bitstream_notification_mode) value that selects between full-frame and subregion notification output modes.

### `FrameOutputBuffer`

A [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream) for full-frame output. Used when **NotificationMode** is **D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM_NOTIFICATION_MODE_FULL_FRAME**.

### `SubregionOutputBuffers`

A [D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_subregion_compressed_bitstream) for per-subregion output. Used when **NotificationMode** is **D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM_NOTIFICATION_MODE_SUBREGIONS**.

## Remarks

**FrameOutputBuffer** and **SubregionOutputBuffers** are members of a union. Only the member corresponding to the selected **NotificationMode** is used.

## See also

[D3D12_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_output_arguments1)