## Description

Contains CPU-buffer move region information for the motion vectors feature. All pixels inside a move rect move in the same direction.

## Members

### `NumMoveRegions`

Number of elements in pMoveRegions.

### `pMoveRegions`

Pointer to an array of [D3D12_VIDEO_ENCODER_MOVE_RECT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_move_rect) structures specifying move regions.

### `MotionSearchModeConfiguration`

A [D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_CONFIG](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_motion_search_mode_config) specifying how the motion input vectors are used.

### `SourceDPBFrameReference`

An index into the picture parameters DPB descriptor indicating which previous reference frame this move region refers to.

### `MotionUnitPrecision`

A [D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_input_motion_unit_precision) defining the numerical unit used in the move rect values.

### `Flags`

A combination of [D3D12_VIDEO_ENCODER_MOVEREGION_INFO_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_moveregion_info_flags).

## Remarks

## See also