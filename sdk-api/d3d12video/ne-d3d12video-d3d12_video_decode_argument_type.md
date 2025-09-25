# D3D12_VIDEO_DECODE_ARGUMENT_TYPE enumeration

## Description

Specifies the argument type of a [D3D12_VIDEO_DECODE_FRAME_ARGUMENT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_frame_argument).

## Constants

### `D3D12_VIDEO_DECODE_ARGUMENT_TYPE_PICTURE_PARAMETERS`

The argument is a picture decoding parameter buffer.

### `D3D12_VIDEO_DECODE_ARGUMENT_TYPE_INVERSE_QUANTIZATION_MATRIX`

The argument is an inverse quantization matrix buffer.

### `D3D12_VIDEO_DECODE_ARGUMENT_TYPE_SLICE_CONTROL`

The argument is a slice control buffer.

### `D3D12_VIDEO_DECODE_ARGUMENT_TYPE_MAX_VALID`

TBD

## Remarks

The values used with the argument type are defined by the DXVA specification for a given codec.

## See also