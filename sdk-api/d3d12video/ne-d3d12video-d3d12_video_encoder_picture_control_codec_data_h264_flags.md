## Description

Specifies flags for the H.264-specific picture control properties.

## Constants

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAG_REQUEST_INTRA_CONSTRAINED_SLICES`

Requests slice-constrained encoding for a frame, in which every slice in the frame is encoded independently from other slices in the same frame. Check for support in [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_FLAGS_H264_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_support_h264_flags). This mode restricts the motion vector search range to the region box of the current slice, i.e. motion vectors outside the slice boundary can't be used.

## Remarks

## See also