## Description

The **D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_0080** structure specifies the parameters for the intra-refresh mode that should be used when triggering intra-refresh sessions.

## Members

### `Mode`

A [**D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_intra_refresh_mode_0080) value that indicates the type of intra refresh to be used.

### `IntraRefreshDuration`

The duration of the intra-refresh session, in number of frames. If **Mode** is **D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_MODE_ROW_BASED_0080**, **IntraRefreshDuration** and the frame height define the size of the I rows for the duration of the IR session.

## Remarks

When triggering an intra-refresh session, the host informs the current frame number relative to the [0..**IntraRefreshDuration**) session by setting **IntraRefreshFrameIndex** in the [picture control structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0).

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0)

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)