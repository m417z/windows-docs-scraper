# D3D12_VIDEO_DECODE_TIER enumeration

## Description

Specifies the decoding tier of a hardware video decoder, which determines the required format of application-defined textures and buffers.

## Constants

### `D3D12_VIDEO_DECODE_TIER_NOT_SUPPORTED`

Video decoding is not supported.

### `D3D12_VIDEO_DECODE_TIER_1`

In tier 1, the hardware decoder requires that the application allocate reference textures as a texture array. This is to accommodate hardware requirements that the textures be "close" in address space because the hardware doesn't support a full size pointer for each individual picture buffer. Instead it has one pointer and a more limited bit offset. For more information on texture arrays, see [Introduction To Textures in Direct3D 11](https://learn.microsoft.com/windows/win32/direct3d11/overviews-direct3d-11-resources-textures-intro).

If the decoder hardware requires a unique memory layout that is not supported for operations on other engines or different video operations, the decoder may set the [D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_REFERENCE_ONLY_ALLOCATIONS_REQUIRED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_configuration_flags) configuration flag in the [D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_support) structure when queried for profile support. This flag indicates that the application must allocate references with the [D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flag. The application should use the [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments) structure to set a reference-only output if the output is needed as a future reference frame. The output frame passed to [ID3D12VideoCommandList::DecodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-decodeframe) is a D3D12 resource that can be consumed by other portions of the pipeline and must not have the D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY flag.

#### Tier 1 requirements for compressed input buffers
- All slices for a given frame must be placed in order and must be contiguous, i.e. there must be no gaps between slices. Slice control buffers must specify offset and size parameters that meet this requirement.
- The first slice must begin on a 128 Byte boundary. The offset set in the [D3D12_VIDEO_DECODE_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_compressed_bitstream) structure must be a multiple of 128 Bytes.
- Decoding is supported from buffers allocated with [D3D12_MEMORY_POOL_L0](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool). This is always system memory, but still a D3D12 buffer.
- Decoding is supported from buffers allocated with D3D12_MEMORY_POOL_L1, the default pool, including those allocated with D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE.

### `D3D12_VIDEO_DECODE_TIER_2`

In decode tier 2, textures can be referenced as a texture array or as an array of separate texture 2D resources (each resource having array size of 1). This is more flexible for the caller and is important in scenarios where the resolution changes frequently such as in streaming video, because a texture array can only be allocated and deallocated as a single unit, but separate texture 2D resources can be allocated and deallocated individually.

If decode hardware requires a unique tiling format that is not supported for operations on other engines or different video operations, the decoder may set the [D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_REFERENCE_ONLY_ALLOCATIONS_REQUIRED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_configuration_flags) configuration flag in the [D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_support) structure when queried for profile support. This flag indicates that the application must allocate references with the [D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flag. The application should use the [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments) structure to set a reference only output if the output is needed as a future reference frame. The output frame passed to [ID3D12VideoCommandList::DecodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-decodeframe) is a D3D12 resource that can be consumed by other portions of the pipeline and must not have the D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY flag.

#### Tier 2 requirements for compressed input buffers

These requirements are identical to the tier 1 requirements.

- All slices for a given frame must be placed in order and must be contiguous, i.e. there must be no gaps between slices. Slice control buffers must specify offset and size parameters that meet this requirement.
- The first slice must begin on a 128 Byte boundary. The offset set in the [D3D12_VIDEO_DECODE_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_compressed_bitstream) structure must be a multiple of 128 Bytes.
- Decoding is supported from buffers allocated with [D3D12_MEMORY_POOL_L0](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool). This is always system memory, but still a D3D12 buffer.
- Decoding is supported from buffers allocated with D3D12_MEMORY_POOL_L1, the default pool, including those allocated with D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE.
-

### `D3D12_VIDEO_DECODE_TIER_3`

This field is reserved.

## Remarks

## See also