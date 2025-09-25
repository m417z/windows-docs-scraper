## Description

Represents metadata about an [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) operation.

## Members

### `EncodeErrorFlags`

A **UINT64** representing a bitwise OR combination of values from the [D3D12_VIDEO_ENCODER_ENCODE_ERROR_FLAG](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_encode_error_flags) enumeration specifying information about the encode execution status.

### `EncodeStats`

A [D3D12_VIDEO_ENCODER_OUTPUT_METADATA_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_output_metadata_statistics) representing statistics for an **EncodeFrame** operation.

### `EncodedBitstreamWrittenBytesCount`

Output field that receives a **UINT64** indicating how many bytes were into [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM.pBuffer](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream) plus the value of [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM.FrameStartOffset](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream).

### `WrittenSubregionsCount`

Output field that receives a **UINT64** indicating the number of subregions used to encode the current frame.

This value is coherent with the settings specified in [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC.pFrameSubregionsLayoutData](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc). If a number of subregions was specified, *WrittenSubregionsCount* should match that value. If another mode was used, this field is how the driver reports the final number of subregions. If the output is a full frame, then there is only 1 subregion.

## Remarks

**D3D12_VIDEO_ENCODER_OUTPUT_METADATA** and its child structures are all aligned to a 64-bit access boundary for use with [SetPredication](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setpredication).

## See also