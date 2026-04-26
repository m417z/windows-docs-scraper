## Description

Defines the reported support for frame analysis as output for D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS1.

## Members

### `SupportFlags`

Output parameter. A bitwise or combination of [D3D12_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_frame_analysis_support_flags) values indicating the supported frame analysis capabilities for this resolution.

## Remarks

Only reported when D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT2.FrameAnalysis.Enabled is TRUE and the driver supports it. Zeroed memory otherwise.

## See also

[D3D12_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_frame_analysis_support_flags)