# ID3D11VideoContext::VideoProcessorGetOutputTargetRect

## Description

Gets the current target rectangle for the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `Enabled` [out]

Receives the value **TRUE** if the target rectangle was explicitly set using the [ID3D11VideoContext::VideoProcessorSetOutputTargetRect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputtargetrect) method. Receives the value FALSE if the target rectangle was disabled or was never set.

### `pRect` [out]

If *Enabled* receives the value **TRUE**, this parameter receives the target rectangle. Otherwise, this parameter is ignored.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)