# D3D12DDI_VIDEO_PROCESS_MAX_INPUT_STREAMS_DATA_0020 structure

## Description

Specifies information used to retrieve the maximum number of input data streams that can be enabled for a video processor.
This structure is used in the D3D12DDICAPS_TYPE_VIDEO_PROCESS_MAX_INPUT_STREAMS capabilities check as part of [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `MaxInputStreams`

The maximum number of streams that can be enabled for the video processor at the same time.