## Description

Specifies indices for arrays of per component histogram information.

## Constants

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_Y:0`

If the format is a YUV format, indicates a histogram for the Y component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_U:1`

If the format is a YUV format, indicates a histogram for the U component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_V:2`

If the format is a YUV format, indicates a histogram for the V component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_R:0`

If the format is an RGB/BGR format, indicates a histogram for the R component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_G:1`

If the format is an RGB/BGR format, indicates a histogram for the G component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_B:2`

If the format is an RGB/BGR format, indicates a histogram for the B component.

### `D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_A:3`

If the format has an alpha channel, indicates a histogram for the A component.

## Remarks

The [D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_video_decoder_histogram_component_flags) is the flags enumeration used by [D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d11_4/ns-d3d11_4-d3d11_feature_data_video_decoder_histogram) to allow you to specify one or more components for which histogram data is queried.

## See also