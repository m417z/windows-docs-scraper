# D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE enumeration

## Description

Specifies the alpha fill mode for video processing.

## Constants

### `D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE`

Alpha values inside the target rectangle are set to opaque.

### `D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE_BACKGROUND`

Alpha values inside the target rectangle are set to the alpha value specified in the background color. To set the background color, call the [VideoProcessorSetOutputBackgroundColor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputbackgroundcolor) function.

### `D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE_DESTINATION`

Existing alpha values remain unchanged in the output surface.

### `D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE_SOURCE_STREAM`

Alpha values are taken from an input stream, scaled, and copied to the corresponding destination rectangle for that stream. The input stream is specified in the *StreamIndex* parameter of the [VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode) function.

If the input stream does not have alpha data, the video processor sets the alpha values in the target rectangle to opaque. If the input stream is disabled or the source rectangle is empty, the alpha values in the target rectangle are not modified.

## See also

[VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode)

[VideoProcessorSetOutputBackgroundColor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputbackgroundcolor)