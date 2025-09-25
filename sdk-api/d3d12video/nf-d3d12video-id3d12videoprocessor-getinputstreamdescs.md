# ID3D12VideoProcessor::GetInputStreamDescs

## Description

Gets the input stream descriptions provided when the video processor was created with a call to [ID3D12VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-createvideoprocessor).

## Parameters

### `NumInputStreamDescs`

The size of the array pointed to by *pInputStreamDescs*. Get the number of input stream descriptions associated with the video processor by calling [ID3DVideoProcessor::GetNumInputStreamDescs](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocessor-getnuminputstreamdescs).

### `pInputStreamDescs`

An array of [D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_desc) structures that is populated with the input stream descriptions associated with the video processor.

## Return value

This method returns HRESULT.

## Remarks

## See also