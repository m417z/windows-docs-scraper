# D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAGS_0020 enumeration

## Description

Defines the features that video processor can support.

## Constants

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0022_NONE`

No supported video processor features.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_ALPHA_FILL`

The video processor can set alpha values on the output pixels. For more information, see the [SetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode) function.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_LUMA_KEY`

The video processor can perform luma keying. Luma keying is configured by using the **LumaKey** member of the [D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043) structure. For more information, see the [D3D12DDI_VIDEO_PROCESS_LUMA_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_luma_key_0020) structure.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_STEREO`

The video processor can support 3D stereo video. All drivers that set this capability must support the following stereo formats: **D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_HORIZONTAL**, **D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_VERTICAL**, and **D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_SEPARATE**. For more information, see [SetInputStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat).

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_ROTATION`

The driver can rotate the input data either 90, 180, or 270 degrees clockwise as part of the video processing operation.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_FLIP`

The driver can flip the input data horizontally or vertically, together or separately with a video rotation operation.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_ALPHA_BLENDING`

Alpha blending and a planar alpha may be set in the **AlphaBlending** member of the [D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043) structure. For more information, see the [D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_alpha_blending_0020) structure.

### `D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAG_0020_PIXEL_ASPECT_RATIO`

The driver supports changing the pixel aspect ratio. If the driver does not report this capability, the **SourceAspectRatio** and **DestinationAspectRatio** members of the [D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043) structure must indicate a 1:1 aspect ratio.

## See also

[D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043)

[D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_alpha_blending_0020)

[D3D12DDI_VIDEO_PROCESS_LUMA_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_luma_key_0020)

[SetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode)