# ID3D11VideoContext::VideoProcessorGetOutputConstriction

## Description

Gets the current level of downsampling that is performed by the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `pEnabled` [out]

Receives the value **TRUE** if downsampling was explicitly enabled using the [ID3D11VideoContext::VideoProcessorSetOutputConstriction](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputconstriction) method. Receives the value **FALSE** if the downsampling was disabled or was never set.

### `pSize` [out]

If *Enabled* receives the value **TRUE**, this parameter receives the downsampling size. Otherwise, this parameter is ignored.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)