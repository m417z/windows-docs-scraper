# D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0032 structure

## Description

Creation arguments for creating the Video Processor.

## Members

### `NodeMask`

Represents the set of nodes. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `OutputStream`

Description of immutable output stream properties. See [D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_output_stream_desc_0032).

### `pInputStreams`

An array of immutable input stream properties. See [D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_processor_input_stream_desc_0032). The array size is defined by NumInputStreams.

### `NumInputStreams`

The count of input streams.