## Description

Describes an [ID3D12VideoEncoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoder). Pass this structure into [ID3D12VideoDevice3::CreateVideoEncoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice3-createvideoencoder) to create an instance of **ID3D12VideoEncoder**.

## Members

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Flags`

A bitwise OR combination of values from the [D3D12_VIDEO_ENCODER_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_flags) specifying the flags for encoder creation.

### `EncodeCodec`

A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the desired codec.

### `EncodeProfile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the desired encoding profile.

### `InputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) specifying the format of the source stream.

### `CodecConfiguration`

A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) structure specifying codec configuration parameters.

### `MaxMotionEstimationPrecision`

A value from the [D3D12_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_motion_estimation_precision_mode) enumeration the maximum number of motion vectors allowed.

## Remarks

## See also