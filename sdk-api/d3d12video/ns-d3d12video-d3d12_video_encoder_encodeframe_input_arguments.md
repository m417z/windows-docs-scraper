## Description

Represents input arguments to [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe).

## Members

### `SequenceControlDesc`

A [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc) specifying the configuration for the video sequence

### `PictureControlDesc`

A [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc) specifying the configuration for the video picture.

### `pInputFrame`

An [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) representing the frame to encode.

### `InputFrameSubresource`

A UINT64 specifying the subresource index for *pInputFrame*.

### `CurrentFrameBitstreamMetadataSize`

A UINT64 specifying the number of bytes added to the final bitstream between the end of the last **EncodeFrame** compressed bitstream output and the current call output. This is intended to capture the size of any headers or metadata messages added by the client to the final bitstream which are used as a hint by the rate control algorithms to keep track of the full bitstream size.

## Remarks

## See also