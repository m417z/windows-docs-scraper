# D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAGS_0020 enumeration

## Description

Contains video decode configuration flags.

## Constants

### `D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAG_0020_NONE`

Indicates no configuration flags required.

### `D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAG_0020_HEIGHT_ALIGNMENT_MULTIPLE_32_REQUIRED`

Indicates that the height of the output decoded surfaces must be a multiple of 32.

### `D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAG_0020_POST_PROCESSING_SUPPORTED`

Indicates that the driver supports post processing. If this flag is set, the host decoder can set up post-processing by using the conversion flags in [D3D12DDI_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_conversion_arguments_0021).

### `D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAG_0020_REFERENCE_ONLY_ALLOCATIONS_REQUIRED`

Indicates that reference resources must be allocated with the **D3D12DDI_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY** flag in the [D3D12DDI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_flags_0003) enumeration. References textures must be separate from output textures, similar to performing a format conversion or downscale. This flag must not be set for a value of D3D12DDI_VIDEO_DECODE_TIER_3 or greater. For more information, see the [D3D12DDI_VIDEO_DECODE_TIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_tier_0020) enumeration.

### `D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAG_0032_ALLOW_RESOLUTION_CHANGE_ON_NON_KEY_FRAME`

Indicates that the driver supports resolution change on non-key frames.