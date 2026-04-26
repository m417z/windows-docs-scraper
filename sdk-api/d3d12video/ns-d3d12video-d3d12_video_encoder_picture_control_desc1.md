## Description

Describes the picture control properties for a video encode operation, including support for quantization maps, dirty regions, and motion vectors.

## Members

### `IntraRefreshFrameIndex`

The current frame index in an intra-refresh cycle.

### `Flags`

A combination of [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_flags).

### `PictureControlCodecData`

Codec-specific picture control data as a [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data1).

### `ReferenceFrames`

A [D3D12_VIDEO_ENCODE_REFERENCE_FRAMES](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encode_reference_frames) specifying the reference frames.

### `MotionVectors`

A [D3D12_VIDEO_ENCODER_FRAME_MOTION_VECTORS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_motion_vectors) with motion vector input data. Requires [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_MOTION_VECTORS_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_flags).

### `DirtyRects`

A [D3D12_VIDEO_ENCODER_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_regions) with dirty regions input data. Requires [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_DIRTY_REGIONS_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_flags).

### `QuantizationTextureMap`

A [D3D12_VIDEO_ENCODER_QUANTIZATION_OPAQUE_MAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_quantization_opaque_map) with the GPU quantization map. Requires [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_QUANTIZATION_MATRIX_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_flags).

## Remarks

## See also