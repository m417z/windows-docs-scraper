## Description

Represents a video encoder rate control configuration.

## Members

### `Mode`

A value from the [D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_mode) enumeration specifying the rate control mode.

### `Flags`

A bitwise OR combination of values from the [D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_flags) enumeration.

### `ConfigParams`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control_configuration_params) structure representing rate control configuration parameters corresponding to the specified *Mode*. Note that for absolute QP matrix mode, the configuration arguments are provided per EncodeFrame basis.

If the selected rate control mode is **D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_ABSOLUTE_QP_MAP**, the QP values in *pRateControlQPMap* are treated as absolute QP values.

For the other rate control modes, the QP values in *pRateControlQPMap* are interpreted as a delta QP map to be used for the current frame encode operation. The values provided in the map are incremented/decremented on top of the QP values decided by the rate control algorithm or the baseline QP constant set in CQP mode.

### `TargetFrameRate`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) specifying the target frame rate for the encoded stream. This value is a hint for the rate control budgeting algorithm.

## Remarks

## See also