# D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS_0032 structure

## Description

**D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS_0032** specifies input stream parameters for an input stream passed to [PFND3D12DDI_VIDEO_PROCESS_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0032).

## Members

### `InputStream[2]`

Contains the set of references to be able to perform processing. If stereo format is [D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_SEPARATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_frame_stereo_format_0020), then two sets of input streams must be supplied. If stereo format is any other mode, the first set of reference must be supplied, and the second should be zero initialized.

### `Transform`

Specifies flip, rotation, scale and destination translation for the video input. See [D3D12DDI_VIDEO_PROCESS_TRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_transform_0032).

### `Flags`

Specifies options for the input stream. See [D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_input_stream_flags_0020).

### `RateInfo`

Specifies frame rate and input and output indices for framerate conversion and deinterlacing. See [D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_RATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_input_stream_rate_info_0032).

### `FilterLevels[D3D12DDI_VIDEO_PROCESS_MAX_FILTERS_0020]`

The level to apply for each enabled filter. Filter level is specified in the order that filters appear in the [D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_flags_0020). Specify 0 if a filter is not enabled or the filter index is reserved.

### `AlphaBlending`

The planar alpha for an input stream on the video processor. See [D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_alpha_blending_0020).

## Remarks

The size of the video decoder heap is static at compile time.

## See also

[**PFND3D12DDI_VIDEO_PROCESS_FRAME_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0032)