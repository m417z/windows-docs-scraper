## Description

Specifies flags for video encoder features.

## Constants

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_GENERAL_SUPPORT_OK`

Indicates whether the given configuration is supported by the encoder in combination with the rest of the flags to convey certain limitations or no general support. The Direct3D 12 Debug layer can provide further information.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_RECONFIGURATION_AVAILABLE`

Support for changing the rate control in the middle of the encoding session.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RESOLUTION_RECONFIGURATION_AVAILABLE`

Support for changing the resolution in the middle of the encoding session.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_VBV_SIZE_CONFIG_AVAILABLE`

Support for configuring the VBV Initial fullness and capacity for rate control algorithms.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_FRAME_ANALYSIS_AVAILABLE`

Support for rate control modes that involve frame analysis to optimize the bitrate usage at the cost of a slower performance. When this flag is reported by the driver, further support for performing two pass at lower resolutions can be queried in [D3D12_FEATURE_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RECONSTRUCTED_FRAMES_REQUIRE_TEXTURE_ARRAYS`

When this flag is set, textures referring reconstructed pictures can only be referenced as a texture array, as opposed to an array of separate texture 2D resources with each resource having array size of 1. When this capability is not required, there is more flexibility for the host. This is important for scenarios where the resolution changes frequently and the DPB needs to be flushed for an IDR frame, because a texture array can only be allocated and deallocated as an single unit, but separate texture 2D resources can be allocated and deallocated individually.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_DELTA_QP_AVAILABLE`

Support for Delta QP usage in rate control

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGION_LAYOUT_RECONFIGURATION_AVAILABLE`

Support for dynamic subregion layout changes during an encoding session.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_ADJUSTABLE_QP_RANGE_AVAILABLE`

Support for adjustable QP range in rate control.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_INITIAL_QP_AVAILABLE`

Support for adjustable initial QP in rate control.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_MAX_FRAME_SIZE_AVAILABLE`

Support for setting a maximum cap in the bitrate algorithm per each encoded frame.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SEQUENCE_GOP_RECONFIGURATION_AVAILABLE`

Support for dynamic GOP changes during an encode session.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_MOTION_ESTIMATION_PRECISION_MODE_LIMIT_AVAILABLE`

Support for the caller to limit the precision used for motion search on frame encode.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_EXTENSION1_SUPPORT` : 0x2000

Support for rate control extension 1 configurations.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RATE_CONTROL_QUALITY_VS_SPEED_AVAILABLE` : 0x4000

Support for quality versus speed trade-off configuration in rate control.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_READABLE_RECONSTRUCTED_PICTURE_LAYOUT_AVAILABLE` : 0x8000

Support for readable reconstructed picture layouts.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_QP_MAP_METADATA_AVAILABLE`

Support for per-block QP map metadata output. When supported, the application can enable [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_QP_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags).

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_SATD_MAP_METADATA_AVAILABLE`

Support for per-block SATD map metadata output. When supported, the application can enable [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SATD_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags).

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_PER_BLOCK_RC_BIT_ALLOCATION_MAP_METADATA_AVAILABLE`

Support for per-block rate control bit allocation map metadata output. When supported, the application can enable [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_RC_BIT_ALLOCATION_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags).

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGION_NOTIFICATION_ARRAY_OF_BUFFERS_AVAILABLE`

Support for subregion compressed bitstream notification using an array of separate output buffers, one per subregion.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGION_NOTIFICATION_SINGLE_BUFFER_AVAILABLE`

Support for subregion compressed bitstream notification using a single contiguous output buffer for all subregions.

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_FRAME_PSNR_METADATA_AVAILABLE`

Support for frame-level PSNR metadata output. When supported, the application can enable [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_FRAME_PSNR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags).

### `D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGIONS_PSNR_METADATA_AVAILABLE`

Support for subregion-level PSNR metadata output. When supported, the application can enable [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SUBREGIONS_PSNR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags).
## Remarks

D3D12_VIDEO_ENCODER_SUPPORT_FLAG_GENERAL_SUPPORT_OK indicates that whether there is general support. The rest of the flags can be combined to convey further information.

General support always expected.

- There is support for all buffers to be allocated with [D3D12_MEMORY_POOL_L0](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_memory_pool). This is always system memory, but still a D3D12 buffer.
- There is support for all buffers to be allocated with [D3D12_MEMORY_POOL_L1](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_memory_pool)), the default pool, including those allocated with [D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_cpu_page_property).

## See also