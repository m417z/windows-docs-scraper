## Description

The **D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAGS_0082_0** enumeration specified error(s) encountered during the associated [**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command execution.

## Constants

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_NO_ERROR`

No errors occurred.

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_CODEC_PICTURE_CONTROL_NOT_SUPPORTED`

The specified codec picture control description is not supported.

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_SUBREGION_LAYOUT_CONFIGURATION_NOT_SUPPORTED`

The specified sub-region layout configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_INVALID_REFERENCE_PICTURES`

The specified reference pictures are invalid.

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_RECONFIGURATION_REQUEST_NOT_SUPPORTED`

The requested reconfiguration is not supported.

### `D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAG_0082_0_INVALID_METADATA_BUFFER_SOURCE`

The metadata buffer source is invalid.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0)