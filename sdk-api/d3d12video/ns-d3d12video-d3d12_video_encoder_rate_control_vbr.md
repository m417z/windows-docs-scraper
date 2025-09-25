## Description

Represents a rate control structure definition for variable bitrate mode.

## Members

### `InitialQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_INITIAL_QP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, allows the Initial QP to be used by the rate control algorithm.

### `MinQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_QP_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits QP range of the rate control algorithm.

### `MaxQP`

When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_QP_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits QP range of the rate control algorithm.

### `MaxFrameBitSize`

The maximum size, in bits, for each frame to be coded. When [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_MAX_FRAME_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, limits each frame maximum size in the rate control algorithm.

### `TargetAvgBitRate`

Average bitrate to be used, in bits/second.

### `PeakBitRate`

The maximum bit rate that can be reached in bits/second.

### `VBVCapacity`

When [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_VBV_SIZE_CONFIG_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, specifies the capacity in bits of the Video Buffer Verifier to be used in the rate control algorithm.

### `InitialVBVFullness`

When [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_VBV_SIZE_CONFIG_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) is enabled, specifies the initial fullness in bits of the Video Buffer Verifier to be used in the rate control algorithm.

## Remarks

## See also