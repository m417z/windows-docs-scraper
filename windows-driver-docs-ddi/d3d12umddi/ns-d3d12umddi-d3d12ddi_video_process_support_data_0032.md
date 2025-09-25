# D3D12DDI_VIDEO_PROCESS_SUPPORT_DATA_0032 structure

## Description

The **D3D12DDI_VIDEO_PROCESS_SUPPORT_DATA_0032** structure specifies information used to retrieve the capabilities for a video processor. It's used by the [PFND3D12DDI_VIDEO_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) callback function, with the **Type** parameter in [D3D12DDIARG_VIDEO_GETCAPS_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020) set to D3D12DDICAPS_TYPE_VIDEO_0020_PROCESS_SUPPORT.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `InputSample`

Input Width, Height, and Format. See [D3D12DDI_VIDEO_SAMPLE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_sample_description_0020).

### `InputFieldType`

The interlaced field type of the input sample. See [D3D12DDI_VIDEO_FIELD_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_field_type_0020).

### `InputStereoFormat`

The stereo format of the input. See [D3D12DDI_VIDEO_FRAME_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_frame_stereo_format_0020).

### `InputFrameRate`

The input frame rate.

### `OutputFormat`

The output DXGI format and color space. See [D3D12DDI_VIDEO_FORMAT_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_format_description_0020).

### `OutputStereoFormat`

The stereo format of the output. See [D3D12DDI_VIDEO_FRAME_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_frame_stereo_format_0020).

### `OutputFrameRate`

The frame rate of the output.

### `SupportFlags`

Indicates if the conversion from input format and color space to output format and color space is supported. See [D3D12DDI_VIDEO_PROCESS_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_support_flags_0022) for details,

### `ScaleSupport`

Indicates the supported output scale range for the input to output processing. See [D3D12DDI_VIDEO_SCALE_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_scale_support_0032).

### `FeatureSupport`

A bitwise OR of zero or more flags from the [D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_feature_support_flags_0020) enumeration.

### `DeinterlaceSupport`

The deinterlace modes supported by the driver. See [D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_deinterlace_flags_0020).

### `AutoProcessingSupport`

Indicates the type of auto processing operations supported by driver.

### `FilterSupport`

A bitwise OR of zero or more flags from the [D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_flags_0020) enumeration.

### `FilterRangeSupport`

The list of filter range values. The order of the range values should be specified in the same order that the filters appear in the D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS. D3D12DDI_VIDEO_PROCESS_MAX_FILTERS range values are available for current and future filters. The D3D runtime will zero initialize any range value that is not supported by the driver.
The value of D3D12DDI_VIDEO_PROCESS_MAX_FILTERS is defined as such:

```c
#define D3D12DDI_VIDEO_PROCESS_MAX_FILTERS_0020 32
```