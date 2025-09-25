# ID3D11VideoContext::VideoProcessorGetStreamPixelAspectRatio

## Description

Gets the pixel aspect ratio for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `pEnabled` [out]

Receives the value **TRUE** if the pixel aspect ratio is specified. Otherwise, receives the value **FALSE**.

### `pSourceAspectRatio` [out]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure. If **pEnabled* is **TRUE**, this parameter receives the pixel aspect ratio of the source rectangle.

### `pDestinationAspectRatio` [out]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure. If **pEnabled* is **TRUE**, this parameter receives the pixel aspect ratio of the destination rectangle.

## Remarks

When the method returns, if **pEnabled* is **TRUE**, the *pSourceAspectRatio* and *pDestinationAspectRatio* parameters contain the pixel aspect ratios. Otherwise, the default pixel aspect ratio is 1:1 (square pixels).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)