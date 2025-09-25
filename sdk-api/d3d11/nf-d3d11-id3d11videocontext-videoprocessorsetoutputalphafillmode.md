# ID3D11VideoContext::VideoProcessorSetOutputAlphaFillMode

## Description

Sets the alpha fill mode for data that the video processor writes to the render target.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `AlphaFillMode` [in]

The alpha fill mode, specified as a [D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_alpha_fill_mode) value.

### `StreamIndex` [in]

The zero-based index of an input stream. This parameter is used if *AlphaFillMode* is **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_SOURCE_STREAM**. Otherwise, the parameter is ignored.

## Remarks

To find out which fill modes the device supports, call the [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) method. If the driver reports the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_FILL** capability, the driver supports all of the fill modes. Otherwise, the *AlphaFillMode* parameter must be **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE**.

The default fill mode is **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE**.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)