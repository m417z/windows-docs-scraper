## Description

Specifies flags for video encoder sequence control properties.

## Constants

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_RESOLUTION_CHANGE`

Indicates a change in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.PictureTargetResolution](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc).

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_RATE_CONTROL_CHANGE`

Indicates a change in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.RateControl](https://learn.microsoft.com/windows/win32/api/d3d12video/(ns-d3d12video-d3d12_video_encoder_sequence_control_desc).

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_SUBREGION_LAYOUT_CHANGE`

Indicates a change in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.SelectedLayoutMode](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc) or [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.pFrameSubregionsLayoutData](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc).

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_REQUEST_INTRA_REFRESH`

Starts an intra-refresh session starting at this frame using the configuration in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.IntraRefreshConfig](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc).

### `D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_GOP_SEQUENCE_CHANGE`

Indicates a change in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.CodecGOPSequence](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc).

## Remarks

Note that depending on the codec, a request for reconfiguration might need to insert an IDR in the bitstream and new SPS headers.

## See also