# D3D12DDI_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS_0021 structure

## Description

Output stream arguments for video decode.

## Members

### `hDrvOutputTexture2D`

The output texture. If decode conversion is enabled, this output specifies the post conversion output. If decode conversion is not enabled, this is the decode output.

### `OutputSubresource`

The output subresource to use for the *hDrvOutputTexture2D* parameter. If the output is an array, this allows specifying array indices.

### `ConversionArguments`

Optional output conversion parameters.