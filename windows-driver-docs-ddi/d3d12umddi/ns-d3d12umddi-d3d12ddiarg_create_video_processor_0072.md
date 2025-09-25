## Description

The **D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072** structure contains the arguments used to create a video processor.

## Members

### `NodeMask`

Represents the set of nodes. For single GPU operation, set this value to zero (0). If there are multiple GPU nodes, set a bit to identify the physical adapter of the device to which the command queue applies. Each bit in the mask corresponds to a single node. Only one bit may be set.

### `OutputStream`

A [**D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_output_stream_desc_0032) structure describing the output stream.

### `pInputStreams`

Pointer to a [**D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_processor_input_stream_desc_0043) structure for the input stream.

### `NumInputStreams`

Number of input streams.

### `hDrvProtectedResourceSession`

Handle to the protected resource session acquired at object creation time.

## Remarks

A video processor holds state for a video processing session. State includes required intermediate memory, cached processing data, or other temporary working space. A separate video processor must be created for each content stream by the application.

## See also

[**PFND3D12DDI_CREATEVIDEOPROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoprocessor_0072)