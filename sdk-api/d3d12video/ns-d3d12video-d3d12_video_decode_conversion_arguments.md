# D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS structure

## Description

Specifies the parameters for decode output conversion. [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments) is used for the same purpose, but provides additional fields for output width and output height.

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

## Remarks

Scaling is specified by the difference between the native decode texture size and the output texture size.

Use [D3D12_FEATURE_VIDEO_DECODE_CONVERSION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) to determine if a conversion combination is supported.

The source and destination resolution and format are communicated by the resource properties of decode textures and the output buffer specified in [ID3D12VideoCommandList::DecodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-decodeframe).

## See also