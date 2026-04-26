## Description

Describes the frame analysis configuration for a video encoder support query.

## Members

### `Enabled`

A boolean value indicating whether frame analysis is enabled for this support query.

### `Pow2DownscaleFactor`

The power-of-two downscale factor for the frame analysis pass. For example, a value of 1 means the 1st pass dimensions are half the full resolution, and a value of 2 means the 1st pass dimensions are a quarter of the full resolution. A value of 0 indicates full resolution frame analysis.

## Remarks

## See also

[D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_rate_control_frame_analysis)