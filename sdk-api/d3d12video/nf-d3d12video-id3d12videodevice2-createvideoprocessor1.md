## Description

Creates a video processor instance with support for protected resources.

## Parameters

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `pOutputStreamDesc`

A pointer to a D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC(ns-d3d12video-d3d12_video_process_output_stream_desc) structure describing the output stream.

### `NumInputStreamDescs`

The number of input streams provided in the *pInputStreamDescs* parameter.

### `pInputStreamDescs`

A pointer to a list of D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC(ns-d3d12video-d3d12_video_process_input_stream_desc) structures the input streams. The number of structures provided should match the value specified in the *NumInputStreamDescs* parameter.

### `pProtectedResourceSession`

A [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) for managing access to protected resources.

### `riid`

The globally unique identifier (GUID) for the video processor interface.

### `ppVideoProcessor`

A pointer to a memory block that receives a pointer to the [ID3D12VideoProcessor1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoprocessor1) interface

## Return value

This method returns HRESULT.

## Remarks

To change the parameters set during creation, you must recreate the video processor object.

## See also