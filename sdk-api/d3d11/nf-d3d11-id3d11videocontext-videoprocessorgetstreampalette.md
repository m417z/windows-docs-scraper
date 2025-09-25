# ID3D11VideoContext::VideoProcessorGetStreamPalette

## Description

Gets the color-palette entries for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Count` [in]

The number of entries in the *pEntries* array.

### `pEntries` [out]

A pointer to a **UINT** array allocated by the caller. The method fills the array with the palette entries. For RGB streams, the palette entries use the **DXGI_FORMAT_B8G8R8A8** representation. For YCbCr streams, the palette entries use the **DXGI_FORMAT_AYUV** representation.

## Remarks

This method applies only to input streams that have a palettized color format. Palettized formats with 4 bits per pixel (bpp) use 16 palette entries. Formats with 8 bpp use 256 entries.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)