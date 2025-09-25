# D3D12DDI_VIDEO_DECODE_CONVERSION_ARGUMENTS_0021 structure

## Description

Specifies the arguments for decode output conversion.

## Members

### `Enable`

Indicates whether decode conversion should be used.

### `hDrvReferenceTexture2D`

If down sampling is enabled, the output at decode resolution, color space, and format may be required for future decode submissions. If it is not needed, specify NULL.

### `ReferenceSubresource`

The subresource index to use of the *hDrvReferenceTexture2D* argument.

### `OutputColorSpace`

The target color space of the output.

### `DecodeColorSpace`

The source decoded color space before conversion.

## Remarks

Scaling is specified by the difference in reference texture size versus the output texture size.

Use **D3D12DDICAPS_TYPE_VIDEO_DECODE_CONVERSION_SUPPORT** to determine if a conversion combination is supported.

A source and destination resolution and format are communicated by the resource properties of reference textures versus the output buffer specified in the pfnDecodeFrame callback function.

Support for scaling and format conversion during decode can also be queried with **D3D12DDICAPS_TYPE_VIDEO_DECODE_CONVERSION_SUPPORT**. The source size for the scale is the source stream width and height set during video decoder creation. The output size for the scale is the width and height of the output texture passed into the pfnDecodeFrame callback function.