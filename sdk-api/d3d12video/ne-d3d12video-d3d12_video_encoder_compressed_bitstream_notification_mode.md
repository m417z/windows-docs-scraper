## Description

Specifies the bitstream notification mode for a video encode operation.

## Constants

### `D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM_NOTIFICATION_MODE_FULL_FRAME`

The full frame encoding process is used. No subregion notifications are issued.

### `D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM_NOTIFICATION_MODE_SUBREGIONS`

Subregion notification mode is enabled. The driver signals fences as individual subregions (for example, slices or tiles) complete, allowing the application to begin consuming results before the entire frame is encoded.

## Remarks

Check for feature support using [D3D12_VIDEO_ENCODER_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before enabling subregion notification mode.

## See also

[D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream1)

[D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_subregion_compressed_bitstream)