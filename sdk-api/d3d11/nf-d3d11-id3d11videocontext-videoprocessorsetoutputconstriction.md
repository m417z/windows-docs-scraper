# ID3D11VideoContext::VideoProcessorSetOutputConstriction

## Description

Sets the amount of downsampling to perform on the output.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `Enable`

If **TRUE**, downsampling is enabled. Otherwise, downsampling is disabled and the **Size** member is ignored.

### `Size`

The sampling size.

## Remarks

Downsampling is sometimes used to reduce the quality of premium content when other forms of content protection are not available. By default, downsampling is disabled.

If the *Enable* parameter is **TRUE**, the driver downsamples the composed image to the specified size, and then scales it back to the size of the target rectangle.

The width and height of *Size* must be greater than zero. If the size is larger than the target rectangle, downsampling does not occur.

To use this feature, the driver must support downsampling, indicated by the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_CONSTRICTION** capability flag. To query for this capability, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)