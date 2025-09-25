## Description

Represents intra refresh settings for video encoding.

## Members

### `Mode`

A value from the [D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_intra_refresh_mode) enumeration specifying the intra refresh mode.

### `IntraRefreshDuration`

A UINT64 specifying the duration of the intra-refresh session, as a number of frames . For D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE_ROW_BASED, this value and the frame height define the size of the I rows for the duration of the IR session.

## Remarks

When triggering an intra-refresh session, the host informs the current frame number relative to the [0..*IntraRefreshDuration*) session by setting *IntraRefreshFrameIndex* in the picture control structures.

## See also