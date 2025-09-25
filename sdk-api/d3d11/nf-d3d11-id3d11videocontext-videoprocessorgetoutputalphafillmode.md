# ID3D11VideoContext::VideoProcessorGetOutputAlphaFillMode

## Description

Gets the current alpha fill mode for the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `pAlphaFillMode` [out]

Receives the alpha fill mode, as a [D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_alpha_fill_mode) value.

### `pStreamIndex` [out]

If the alpha fill mode is **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_SOURCE_STREAM**, this parameter receives the zero-based index of an input stream. The input stream provides the alpha values for the alpha fill.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)