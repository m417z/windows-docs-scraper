# D3D11_VIDEO_DECODER_CAPS enumeration

## Description

Specifies capabilities of the video decoder.

## Constants

### `D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE:0x1`

Indicates that the graphics driver supports at least a subset of downsampling operations.

### `D3D11_VIDEO_DECODER_CAPS_NON_REAL_TIME:0x2`

Indicates that the decoding hardware cannot support the decode operation in real-time. Decoding is still supported for transcoding scenarios.

With this capability, it is possible that decoding can occur in real-time if downsampling is enabled.

### `D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE_DYNAMIC:0x4`

Indicates that the driver supports changing down sample parameters after the initial down sample parameters have been applied. For more information, see [ID3D11VideoContext1::DecoderUpdateDownsampling](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-decoderupdatedownsampling).

### `D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE_REQUIRED:0x8`

### `D3D11_VIDEO_DECODER_CAPS_UNSUPPORTED:0x10`

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)