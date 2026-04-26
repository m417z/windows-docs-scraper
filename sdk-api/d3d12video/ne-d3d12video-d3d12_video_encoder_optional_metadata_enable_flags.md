## Description

Specifies which optional metadata features are enabled for a video encode operation. These flags are used with [D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments1) and [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments1).

## Constants

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_NONE` : 0x0

No additional optional metadata is present. All previously existing mandatory metadata and stats are still included for backward compatibility.

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_QP_MAP` : 0x1

QP map output in metadata is enabled. The reported QP values are the final QP values used to encode each block, including any QP delta map applied on top of the rate control algorithm's QP value. Check [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_QP_MAP_METADATA_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before using this flag.

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SATD_MAP` : 0x2

SATD (Sum of Absolute Transformed Differences) map output in metadata is enabled. The reported SATD values are before quantization for each block. Check [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_SATD_MAP_METADATA_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before using this flag.

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_RC_BIT_ALLOCATION_MAP` : 0x4

Per-block rate control bit allocation output in metadata is enabled. The driver writes the number of allocated bits used for each block. Check [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_RC_BIT_ALLOCATION_MAP_METADATA_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before using this flag.

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_FRAME_PSNR` : 0x8

Frame-level PSNR (Peak Signal-to-Noise Ratio) output stats are enabled. The driver writes the PSNR of Y (and optionally U and V in that order) components. Check [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_FRAME_PSNR_METADATA_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before using this flag.

### `D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SUBREGIONS_PSNR` : 0x10

Subregion-level PSNR output stats are enabled. The driver writes the PSNR of Y (and optionally U and V in that order) components for each frame subregion. Check [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGIONS_PSNR_METADATA_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) before using this flag.

## Remarks

When a flag is not set, the driver can skip calculating that metadata during encoding to avoid performance impact.

## See also

[D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments1)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments1)