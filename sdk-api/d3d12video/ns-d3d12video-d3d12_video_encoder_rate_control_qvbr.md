## Description

Represents a rate control structure definition for constant quality target with constrained bitrate.

## Members

### `InitialQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_INITIAL_QP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, allows the Initial QP to be used by the rate control algorithm.

### `MinQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_QP_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits QP range of the rate control algorithm.

### `MaxQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_QP_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits QP range of the rate control algorithm.

### `MaxFrameBitSize`

Maximum size in bits for each frame to be coded. When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_MAX_FRAME_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits each frame maximum size in the rate control algorithm.

### `TargetAvgBitRate`

Indicates the target average bit rate, in bits/second.

### `PeakBitRate`

Indicates the maximum bit rate that can be reached in bits/second while using this rate control mode.

### `ConstantQualityTarget`

The quality level target. The values are codec-specific as each standard defines the range for this argument.

## Remarks

## See also