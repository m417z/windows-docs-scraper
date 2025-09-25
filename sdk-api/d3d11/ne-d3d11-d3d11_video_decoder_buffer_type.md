# D3D11_VIDEO_DECODER_BUFFER_TYPE enumeration

## Description

Specifies a type of compressed buffer for decoding.

## Constants

### `D3D11_VIDEO_DECODER_BUFFER_PICTURE_PARAMETERS:0`

Picture decoding parameter buffer.

### `D3D11_VIDEO_DECODER_BUFFER_MACROBLOCK_CONTROL:1`

Macroblock control command buffer.

### `D3D11_VIDEO_DECODER_BUFFER_RESIDUAL_DIFFERENCE:2`

Residual difference block data buffer.

### `D3D11_VIDEO_DECODER_BUFFER_DEBLOCKING_CONTROL:3`

Deblocking filter control command buffer.

### `D3D11_VIDEO_DECODER_BUFFER_INVERSE_QUANTIZATION_MATRIX:4`

Inverse quantization matrix buffer.

### `D3D11_VIDEO_DECODER_BUFFER_SLICE_CONTROL:5`

Slice-control buffer.

### `D3D11_VIDEO_DECODER_BUFFER_BITSTREAM:6`

Bitstream data buffer.

### `D3D11_VIDEO_DECODER_BUFFER_MOTION_VECTOR:7`

Motion vector buffer.

### `D3D11_VIDEO_DECODER_BUFFER_FILM_GRAIN:8`

Film grain synthesis data buffer.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoContext::GetDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-getdecoderbuffer)