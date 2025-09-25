## Description

Encodes a bitstream.

## Parameters

### `pEncoder`

A [ID3D12VideoEncoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoder) representing the video encoder to be used for the encode operation.

### `pHeap`

A [ID3D12VideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap) representing the video encoder heap to be used for this operation.

The encoder heap object allocation must not be released before any in-flight GPU commands that references it finish execution.

Note that the reconfigurations in recorded commands input arguments done within allowed bounds (e.g. different target resolutions in allowed lists of resolutions) can co-exist in-flight with the same encoder heap instance, providing the target resolution is supported by the given encoder heap.

In the current release, we only support one execution flow at a time using the same encoder or encoder heap instances. All commands against these objects must be recorded and submitted in a serialized order, i.e. from a single CPU thread or synchronizing multiple threads in such way that the commands are recorded in a serialized order.

The video encoder and video encoder heap may be used to record commands from multiple command lists, but may only be associated with one command list at a time. The application is responsible for synchronizing single accesses to the video encoder and video encoder heap at a time. The application must also record video encoding commands against the video encoder and video encoder heaps in the order that they are executed on the GPU.

### `pInputArguments`

A [D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments) representing input arguments for the encode operation.

### `pOutputArguments`

A [D3D12_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_output_arguments) representing output arguments for the encode operation.

## Remarks

## See also