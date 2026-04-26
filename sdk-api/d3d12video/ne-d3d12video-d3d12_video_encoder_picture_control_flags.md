## Description

Specifies video encoder picture control flags.

## Constants

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_USED_AS_REFERENCE_PICTURE`

The associated frame will be used as a reference frame in future encode commands. Indicates that the reconstructed picture along with the bitstream should be output for the host to place it in future calls in the reconstructed pictures reference list.

Note that there might be limitations for some frame types to be marked as references. Check feature support before setting this value.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_QUANTIZATION_MATRIX_INPUT`

Enable GPU quantization map input via [D3D12_VIDEO_ENCODER_QUANTIZATION_OPAQUE_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_quantization_opaque_map). Also requires D3D12_VIDEO_ENCODER_RATE_CONTROL_FLAG_ENABLE_DELTA_QP to be set.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_DIRTY_REGIONS_INPUT`

Enable dirty regions input via [D3D12_VIDEO_ENCODER_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_regions). The associated ID3D12VideoEncoderHeap must have been created with D3D12_VIDEO_ENCODER_HEAP_FLAG_ALLOW_DIRTY_REGIONS.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_MOTION_VECTORS_INPUT`

Enable motion vectors input via [D3D12_VIDEO_ENCODER_FRAME_MOTION_VECTORS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_motion_vectors).

## Remarks

Values from this enumeration are used by [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc).

If this flag is not set, the [D3D12_VIDEO_ENCODER_RECONSTRUCTED_PICTURE.pReconstructedPicture](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reconstructed_picture) can be nullptr in the associated call to [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe).

## See also