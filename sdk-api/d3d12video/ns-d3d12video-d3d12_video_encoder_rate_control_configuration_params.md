## Description

Represents video encoder rate control structure definitions for a [D3D12_VIDEO_ENCODER_RATE_CONTROL](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control) structure.

## Members

### `DataSize`

The data size of the provided rate control structure.

### `pConfiguration_CQP`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL_CQP](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control_cqp) structure representing the rate control structure definition for constant quantization parameter mode.

### `pConfiguration_CBR`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL_CBR](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control_cbr) structure representing the rate control structure definition for constant bitrate mode.

### `pConfiguration_VBR`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL_VBR](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control_cqp) structure representing the rate control structure definition for variable bitrate mode.

### `pConfiguration_QVBR`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL_QVBR](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control_vbr) structure representing the rate control structure definition for constant quality target with constrained bitrate mode.

## Remarks

## See also