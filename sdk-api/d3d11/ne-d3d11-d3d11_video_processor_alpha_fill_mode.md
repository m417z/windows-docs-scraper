# D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE enumeration

## Description

Specifies the alpha fill mode for video processing.

## Constants

### `D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE:0`

Alpha values inside the target rectangle are set to opaque.

### `D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_BACKGROUND:1`

Alpha values inside the target rectangle are set to the alpha value specified in the background color. To set the background color, call the [ID3D11VideoContext::VideoProcessorSetOutputBackgroundColor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputbackgroundcolor) method.

### `D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_DESTINATION:2`

Existing alpha values remain unchanged in the output surface.

### `D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_SOURCE_STREAM:3`

Alpha values are taken from an input stream, scaled, and copied to the corresponding destination rectangle for that stream. The input stream is specified in the *StreamIndex* parameter of the [ID3D11VideoContext::VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputalphafillmode) method.

If the input stream does not have alpha data, the video processor sets the alpha values in the target rectangle to opaque. If the input stream is disabled or the source rectangle is empty, the alpha values in the target rectangle are not modified.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoContext::VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputalphafillmode)