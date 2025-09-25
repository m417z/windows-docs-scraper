## Description

Specifies flags for the HEVC-specific picture control properties.

## Constants

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_FLAG_REQUEST_INTRA_CONSTRAINED_SLICES`

Requests slice constrained encoding for a frame, in which every slice in the frame is encoded independently from other slices in the same frame. Please check for support in [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_FLAGS_HEVC_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_support_hevc_flags). This mode restricts the motion vector search range to the region box of the current slice, i.e. motion vectors outside the slice boundary can't be used.

## Remarks

## See also