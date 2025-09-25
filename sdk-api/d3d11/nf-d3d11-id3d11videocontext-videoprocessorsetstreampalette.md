# ID3D11VideoContext::VideoProcessorSetStreamPalette

## Description

Sets the color-palette entries for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Count` [in]

The number of elements in the *pEntries* array.

### `pEntries` [in]

A pointer to an array of palette entries. For RGB streams, the palette entries use the **DXGI_FORMAT_B8G8R8A8** representation. For YCbCr streams, the palette entries use the **DXGI_FORMAT_AYUV** representation. The caller allocates the array.

## Remarks

This method applies only to input streams that have a palettized color format. Palettized formats with 4 bits per pixel (bpp) use the first 16 entries in the list. Formats with 8 bpp use the first 256 entries.

If a pixel has a palette index greater than the number of entries, the device treats the pixel as white with opaque alpha. For full-range RGB, this value is (255, 255, 255, 255); for YCbCr the value is (255, 235, 128, 128).

If the driver does not report the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability flag, every palette entry must have an alpha value of 0xFF (opaque). To query for this capability, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)