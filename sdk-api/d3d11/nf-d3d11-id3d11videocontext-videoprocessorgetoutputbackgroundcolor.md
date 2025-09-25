# ID3D11VideoContext::VideoProcessorGetOutputBackgroundColor

## Description

Gets the current background color for the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `pYCbCr` [out]

Receives the value **TRUE** if the background color is a YCbCr color, or **FALSE** if the background color is an RGB color.

### `pColor` [out]

A pointer to a [D3D11_VIDEO_COLOR](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_color) structure. The method fills in the structure with the background color.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)