# PDXVAHDSW_VideoProcessBltHD callback function

## Description

Performs a video processing blit.

## Parameters

### `hVideoProcessor` [in]

A handle to the software DXVA-HD video processor.

### `pOutputSurface` [in]

A pointer to the **IDirect3DSurface9** interface of a Direct3D surface that receives the blit.

### `OutputFrame` [in]

The frame number of the output video frame, indexed from zero.

### `StreamCount` [in]

The number of input streams to process.

### `pStreams` [in]

A pointer to an array of [DXVAHD_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_data) structures that contain information about the input streams. The number of elements in the array is given in the *StreamCount* parameter.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_VideoProcessor::VideoProcessBltHD](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-videoprocessblthd)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)