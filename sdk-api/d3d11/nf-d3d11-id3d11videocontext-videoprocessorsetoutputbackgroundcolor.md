# ID3D11VideoContext::VideoProcessorSetOutputBackgroundColor

## Description

Sets the background color for the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `YCbCr` [in]

If **TRUE**, the color is specified as a YCbCr value. Otherwise, the color is specified as an RGB value.

### `pColor` [in]

A pointer to a [D3D11_VIDEO_COLOR](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_color) structure that specifies the background color.

## Remarks

The video processor uses the background color to fill areas of the target rectangle that do not contain a video image. Areas outside the target rectangle are not affected.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)