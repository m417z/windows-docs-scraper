## Description

The **D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAGS_0082_0** enumeration defines the set of flags for the sequence control properties.

## Constants

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_NONE`

No flags.

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_RESOLUTION_CHANGE`

Indicates a change in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.PictureTargetResolution**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0).

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_RATE_CONTROL_CHANGE`

Indicates a change in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.RateControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0).

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_SUBREGION_LAYOUT_CHANGE`

Indicates a change in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.SelectedLayoutMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0) or **FrameSubregionsLayoutData**.

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_REQUEST_INTRA_REFRESH`

Starts an intra-refresh session starting at this frame using the configuration in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.IntraRefreshConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0).

### `D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0082_0_GOP_SEQUENCE_CHANGE`

Indicates a change in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.CodecGopSequence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0).

## Remarks

Depending on the codec, a request for reconfiguration might need to insert an IDR in the bitstream and new SPS headers.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)