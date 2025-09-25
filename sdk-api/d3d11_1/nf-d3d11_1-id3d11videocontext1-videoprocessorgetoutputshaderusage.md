# ID3D11VideoContext1::VideoProcessorGetOutputShaderUsage

## Description

Gets a value indicating whether the output surface from a call to [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) can be read by Direct3D shaders.

## Parameters

### `pVideoProcessor` [in]

Type: **ID3D11VideoProcessor***

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `pShaderUsage` [out]

Type: **BOOL***

A pointer to a boolean value indicating if the output surface can be read by Direct3D shaders. True if the surface rendered using [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) can be read by Direct3D shaders; otherwise, false.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)