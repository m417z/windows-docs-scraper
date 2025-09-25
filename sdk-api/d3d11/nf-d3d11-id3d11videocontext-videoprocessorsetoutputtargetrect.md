# ID3D11VideoContext::VideoProcessorSetOutputTargetRect

## Description

Sets the target rectangle for the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `Enable` [in]

Specifies whether to apply the target rectangle.

### `pRect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the target rectangle. If *Enable* is **FALSE**, this parameter is ignored.

## Remarks

The target rectangle is the area within the destination surface where the output will be drawn. The target rectangle is given in pixel coordinates, relative to the destination surface.

If this method is never called, or if the *Enable* parameter is **FALSE**, the video processor writes to the entire destination surface.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)