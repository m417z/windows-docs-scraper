# D3D12_VIDEO_DECODE_CONFIGURATION structure

## Description

Describes the configuration for a video decoder.

## Members

### `DecodeProfile`

A GUID identifying the profile for the decoder, such as D3D12\_VIDEO\_DECODE\_PROFILE\_H264 or D3D12\_VIDEO\_DECODE\_PROFILE\_HEVC\_MAIN. For a list of supported GUIDs, see [Direct3D 12 Video GUIDs](https://learn.microsoft.com/windows/desktop/medfound/direct3d-12-video-guids).

### `BitstreamEncryption`

A member of the [D3D12\_BITSTREAM\_ENCRYPTION\_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_bitstream_encryption_type) enumeration specifying the type of bitstream encryption. For no encryption, use D3D12\_BITSTREAM\_ENCRYPTION\_TYPE\_NONE.

### `InterlaceType`

A member of the [D3D12\_VIDEO\_FRAME\_CODED\_INTERLACE\_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_coded_interlace_type) enumeration the desired interlace type used by the coded frames.

## Remarks

## See also