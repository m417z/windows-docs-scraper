# D3D12_VIDEO_DECODE_CONFIGURATION_FLAGS enumeration

## Description

Specifies the configuration for video decoding.

## Constants

### `D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_NONE`

No configuration flags.

### `D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_HEIGHT_ALIGNMENT_MULTIPLE_32_REQUIRED`

The height of the output decoded surfaces must be a multiple of 32.

### `D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_POST_PROCESSING_SUPPORTED`

The driver supports post processing. If this flag is set, the host decoder can set up post-processing by using the conversion flags in the [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments).

### `D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_REFERENCE_ONLY_ALLOCATIONS_REQUIRED`

Reference resources must be allocated with the [D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) resource flag. References textures must be separate from output textures, similar to performing a format conversion or downscale. This flag must not be set for [D3D12_VIDEO_DECODE_TIER_3](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) or greater.

### `D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_ALLOW_RESOLUTION_CHANGE_ON_NON_KEY_FRAME`

The decode resolution can be changed on a non-key frame.

## Remarks

## See also