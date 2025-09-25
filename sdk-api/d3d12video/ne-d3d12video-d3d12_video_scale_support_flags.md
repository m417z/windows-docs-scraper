# D3D12_VIDEO_SCALE_SUPPORT_FLAGS enumeration

## Description

Specifies the scaling capabilities of the video scaler.

## Constants

### `D3D12_VIDEO_SCALE_SUPPORT_FLAG_NONE`

All possible output size width/height combinations that exist between the maximum size and minimum size for the extent, inclusive, are supported.

### `D3D12_VIDEO_SCALE_SUPPORT_FLAG_POW2_ONLY`

The scaler only supports output sizes at a power of two scale factors within the range. The x and y scale factors must be the same for both dimensions when this flag is set.

### `D3D12_VIDEO_SCALE_SUPPORT_FLAG_EVEN_DIMENSIONS_ONLY`

The scaler only supports output sizes with even output dimensions.

## Remarks

## See also