# D3D12DDI_VIDEO_DECODE_CONVERSION_ARGUMENTS_0041 structure

## Description

Specifies the arguments for decode output conversion.

## Members

### `Enable`

Indicates whether decode conversion should be used.

### `hDrvReferenceTexture2D`

If down sampling is enabled, the output at decode resolution, color space, and format may be required for future decode submissions. If it is not needed, specify null.

### `ReferenceSubresource`

The subresource index to use of the *hDrvReferenceTexture2D* argument.

### `OutputColorSpace`

The target color space of the output.

### `DecodeColorSpace`

The source decoded color space before conversion.

### `OutputWidth`

The output width of before conversion.

### `OutputHeight`

The output height before conversion.