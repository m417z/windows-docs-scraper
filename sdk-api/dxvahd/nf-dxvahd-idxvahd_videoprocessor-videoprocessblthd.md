# IDXVAHD_VideoProcessor::VideoProcessBltHD

## Description

Performs a video processing blit on one or more input samples and writes the result to a Microsoft Direct3D surface.

## Parameters

### `pOutputSurface` [in]

A pointer to the **IDirect3DSurface9** interface of a Direct3D surface. The output of the video processing operation will be written to this surface. The following surface types can be used:

* A video surface of type **DXVAHD_SURFACE_TYPE_VIDEO_OUTPUT**. See [IDXVAHD_Device::CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface).
* A render-target surface or texture surface created with D3DUSAGE_RENDERTARGET usage.
* A swap chain.
* A swap chain with overlay support (**D3DSWAPEFFECT_OVERLAY**).

### `OutputFrame` [in]

Frame number of the output video frame, indexed from zero.

### `StreamCount` [in]

Number of input streams to process.

### `pStreams` [in]

Pointer to an array of [DXVAHD_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_data) structures that contain information about the input streams. The caller allocates the array and fills in each structure. The number of elements in the array is given in the *StreamCount* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The maximum value of *StreamCount* is given in the **MaxStreamStates** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of that structure.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_VideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_videoprocessor)