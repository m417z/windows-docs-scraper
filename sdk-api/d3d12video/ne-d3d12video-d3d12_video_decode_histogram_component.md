# D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT enumeration

## Description

Specifies indices for arrays of per component histogram information.

## Constants

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_Y`

If the format is a YUV format, indicates a histogram for the Y component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_U`

If the format is a YUV format, indicates a histogram for the U component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_V`

If the format is a YUV format, indicates a histogram for the V component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_R`

If the format is an RGB/BGR format, indicates a histogram for the R component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_G`

If the format is an RGB/BGR format, indicates a histogram for the G component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_B`

If the format is an RGB/BGR format, indicates a histogram for the B component.

### `D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_A`

If the format has an alpha channel, indicates a histogram for the A component.

## Remarks

The [D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_histogram_component_flags) is the flags enumeration used by [D3D12_FEATURE_DATA_VIDEO_DECODE_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_histogram) to allow you to specify one or more components for which histogram data is queried.

## See also