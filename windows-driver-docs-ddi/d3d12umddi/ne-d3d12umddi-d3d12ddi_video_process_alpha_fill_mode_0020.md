# D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_0020 enumeration

## Description

Contains values for alpha fill modes.

## Constants

### `D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_0020_OPAQUE`

Alpha values inside the target rectangle are set to opaque.

### `D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_0020_BACKGROUND`

Alpha values inside the target rectangle are set to the alpha value specified in the background color.

### `D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_0020_DESTINATION`

Existing alpha values remain unchanged in the output surface.

### `D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_0020_SOURCE_STREAM`

Alpha values are taken from an input stream, scaled, and copied to the corresponding destination rectangle for that stream. The input stream is specified in the **AlphaFillModeSourceStreamIndex** member of the [D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_output_stream_desc_0032) structure. If the input stream does not have alpha data, the video processor sets the alpha values in the target rectangle to opaque. If the input stream is disabled or the source rectangle is empty, the alpha values in the target rectangle are not modified.

## Remarks

The alpha fill mode is used in [D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_output_stream_arguments_0032). The **D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_OPAQUE** flag is always supported. The background, destination, and source stream modes are only supported when the driver reports **D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_ALPHA_FILL**.