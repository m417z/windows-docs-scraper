## Description

Describes the resolved PSNR (Peak Signal-to-Noise Ratio) values for the Y, U, and V components of an encoded frame or subregion.

## Members

### `PSNRY`

The PSNR value for the Y (luma) component.

### `PSNRU`

The PSNR value for the U (chroma) component. Set to zero by the driver if not supported.

### `PSNRV`

The PSNR value for the V (chroma) component. Set to zero by the driver if not supported.

## Remarks

The number of available components is determined by [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements1). Components not supported by the driver are written as zero.

For subregion-level PSNR, the resolved buffer contains a packed array of this structure with one element per subregion.

## See also

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments1)