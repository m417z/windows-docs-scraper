# D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS1 structure

## Description

Specifies the parameters for decode output conversion. [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments) is used for the same purpose, but does not contain fields for output width and output height.

## Members

### `Enable`

A boolean value indicating whether decode conversion should be used.

### `pReferenceTexture2D`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) containing the native decoding output. When downsampling is enabled, the output at native decode resolution, color space, and format may be required for future decode submissions (as reference frames, for instance).

### `ReferenceSubresource`

The subresource index of the resource provided in *pDecodeTexture2D* to use.

### `OutputColorSpace`

A value from the [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) enumeration specifying the target color space of the output.

### `DecodeColorSpace`

A value from the [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) enumeration specifying the source-decoded color space before conversion.

### `OutputWidth`

The output width, in pixels.

### `OutputHeight`

The output width, in pixels.

## Remarks

## See also