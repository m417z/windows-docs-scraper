## Description

Specifies video encoder picture control flags.

## Constants

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_USED_AS_REFERENCE_PICTURE`

The associated frame will be used as a reference frame in future encode commands. Indicates that the reconstructed picture along with the bitstream should be output for the host to place it in future calls in the reconstructed pictures reference list.

Note that there might be limitations for some frame types to be marked as references. Check feature support before setting this value.

## Remarks

Values from this enumeration are used by [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc).

If this flag is not set, the [D3D12_VIDEO_ENCODER_RECONSTRUCTED_PICTURE.pReconstructedPicture](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reconstructed_picture) can be nullptr in the associated call to [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe).

## See also