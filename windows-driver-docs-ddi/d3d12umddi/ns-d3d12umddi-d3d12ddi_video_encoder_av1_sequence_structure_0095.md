## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEQUENCE_STRUCTURE_0095** structure is a hint to the driver of the GOP (group of pictures) being used for rate control purposes only for AV1 video encoding.

## Members

### `IntraDistance`

Indicates the distance between intra-only frames (or key frames) in the video sequence, or the number of pictures on a sequence of inter-frame pictures. If set to 0, only the first frame will be an key-frame.

### `InterFramePeriod`

Indicates the period for inter-frames to be inserted within the inter frame structure. Note that if **IntraDistance** is set to 0 for infinite inter frame structure, this value must be greater than zero.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_0082_0)