# D3D12DDI_VIDEO_PROCESS_REFERENCE_INFO_DATA_0020 structure

## Description

Retrieves the number of past and future frames required for a given deinterlace mode. This structure is for the D3D12DDICAPS_VIDEO_PROCESS_REFERENCE_INFO capability check in [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `DeinterlaceMode`

The deinterlacing mode for which to retrieve the number of past and future frames. Only a single mode may be queried at once. See the [D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_deinterlace_flags_0020) enumeration for a list of modes.

### `Filters`

The filters for which to retrieve the number of past and future frames. Multiple filters may be specified. For more information, see the [D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_flags_0020) enumeration.

### `FeatureSupport`

The features for which to retrieve the number of past and future frames. For more information, see the [D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_feature_support_flags_0020) enumeration.

### `InputFrameRate`

The input rate of the stream.

### `OutputFrameRate`

The output rate of the stream.

### `EnableAutoProcessing`

Whether automatic processing is used. TRUE if auto processing is used.

### `PastFrames`

The number of past reference frames required to support this processing.

### `FutureFrames`

The number of future reference frames required to support this processing.

## See also

[D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_deinterlace_flags_0020)

[D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_feature_support_flags_0020)

[D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_flags_0020)