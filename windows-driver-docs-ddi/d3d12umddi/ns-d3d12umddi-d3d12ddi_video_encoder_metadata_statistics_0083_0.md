## Description

The **D3D12DDI_VIDEO_ENCODER_METADATA_STATISTICS_0083_0** structure is used to provide encoding statistics for an [encoding operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0).

## Members

### `AverageQP`

Specifies the average quantization parameter (QP) value used for encoding this frame.

### `IntraCodingUnitsCount`

Specifies the number of intra-coded coding units used in this frame.

### `InterCodingUnitsCount`

Specifies the number of inter-coded coding units used in this frame.

### `SkipCodingUnitsCount`

Specifies the number of skip coding units used in this frame.

### `AverageMotionEstimationXDirection`

Specifies the average motion vector shift in the *X* direction.

### `AverageMotionEstimationYDirection`

Specifies the average motion vector shift in the *Y* direction.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)