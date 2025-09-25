# ID3D12VideoProcessor::GetNumInputStreamDescs

## Description

Gets the number of input stream descriptions provided when the video processor was created with a call to [ID3D12VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-createvideoprocessor).

## Return value

This method returns UINT. Use this value to determine the correct size of the array you pass in the *pInputStreamDescs* parameter to [ID3D12VideoProcessor::GetInputStreamDescs](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocessor-getinputstreamdescs).

## Remarks

## See also