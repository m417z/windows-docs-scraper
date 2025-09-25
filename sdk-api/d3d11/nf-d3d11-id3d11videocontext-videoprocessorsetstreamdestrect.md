# ID3D11VideoContext::VideoProcessorSetStreamDestRect

## Description

Sets the destination rectangle for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

Specifies whether to apply the destination rectangle.

### `pRect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the destination rectangle. If *Enable* is **FALSE**, this parameter is ignored.

## Remarks

The destination rectangle is the portion of the output surface that receives the blit for this stream. The destination rectangle is given in pixel coordinates, relative to the output surface.

The default destination rectangle is an empty rectangle (0, 0, 0, 0). If this method is never called, or if the *Enable* parameter is **FALSE**, no data is written from this stream.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)