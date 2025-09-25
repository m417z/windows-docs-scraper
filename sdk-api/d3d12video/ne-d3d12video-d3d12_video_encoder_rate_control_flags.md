## Description

Specifies flags for a [D3D12_VIDEO_ENCODER_RATE_CONTROL](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control) structure.

## Constants

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_DELTA_QP`

If the selected rate control is [D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE_ABSOLUTE_QP_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_mode), this flag has no effect since the QP values in **D3D12_VIDEO_ENCODER_RATE_CONTROL.pRateControlQPMap** field are used as absolute QP values.

For the other rate control modes, this flag enables the usage of **D3D12_VIDEO_ENCODER_RATE_CONTROL.pRateControlQPMap** to be interpreted as a delta QP map to be used for the current frame encode operation. The values provided in the map are incremented/decremented on top of the QP values decided by the rate control algorithm or the baseline QP constant set in CQP mode.

**Note** Using delta QP adjustment along with some active rate control modes may violate bitrate constraints as it's explicitly altering the QP values that were selected by rate control budgeting algorithm.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_FRAME_ANALYSIS`

If [D3D12_VIDEO_ENCODER_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) is supported, Enables the rate control algorithm to optimize bitrate usage by selecting QP values based on statistics collected by doing frame analysis on a first pass.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_QP_RANGE`

The MinQp/MaxQP values are used as a range for the rate control algorithm.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_INITIAL_QP`

The InitialQP values are used as a range for the rate control algorithm.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_MAX_FRAME_SIZE`

When [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_MAX_FRAME_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) is supported, the rate control algorithm will limit the maximum size per frame to the specified parameter in the rate control configuration.

### `D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_VBV_SIZES`

Enables the usage of VBVCapacity and InitialVBVFullness.

## Remarks

## See also