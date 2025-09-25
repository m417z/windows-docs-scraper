# D3D12_VIDEO_SCALE_SUPPORT structure

## Description

Describes the supported scaling range of output sizes for a video scaler.

## Members

### `OutputSizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure describing the supported output size range for the scaler.

### `Flags`

A member of the [D3D12_VIDEO_SCALE_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_scale_support_flags) enumeration specifying the supported scaling capabilities of the scaler.

## Remarks

By default, all possible output size combinations that exist between the maximum size and minimum size for the extent, inclusive, are supported. *ScaleSupportFlags* may add additional restrictions to the supported scale sizes.
When scaling is not supported, the minimum and maximum sizes should both be set to the input size and no flags should be specified.

## See also