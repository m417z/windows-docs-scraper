# ID3D11VideoContext::VideoProcessorSetStreamPixelAspectRatio

## Description

Sets the pixel aspect ratio for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

Specifies whether the *pSourceAspectRatio* and *pDestinationAspectRatio* parameters contain valid values. Otherwise, the pixel aspect ratios are unspecified.

### `pSourceAspectRatio` [in]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that contains the pixel aspect ratio of the source rectangle. If *Enable* is **FALSE**, this parameter can be **NULL**.

### `pDestinationAspectRatio` [in]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that contains the pixel aspect ratio of the destination rectangle. If *Enable* is **FALSE**, this parameter can be **NULL**.

## Remarks

This function can only be called if the driver reports the [D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_PIXEL_ASPECT_RATIO](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_feature_caps) capability. If this capability is not set, this function will have no effect.

Pixel aspect ratios of the form 0/n and n/0 are not valid.

The default pixel aspect ratio is 1:1 (square pixels).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)

[Picture Aspect Ratio](https://learn.microsoft.com/windows/desktop/medfound/picture-aspect-ratio)