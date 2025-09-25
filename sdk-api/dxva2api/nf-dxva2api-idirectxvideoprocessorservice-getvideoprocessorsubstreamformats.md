# IDirectXVideoProcessorService::GetVideoProcessorSubStreamFormats

## Description

Gets a list of substream formats supported by a specified video processor device.

## Parameters

### `VideoProcDeviceGuid` [in]

A GUID that identifies the video processor device.
To get the list of video processor GUIDs, call [IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessordeviceguids).

### `pVideoDesc` [in]

A pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `RenderTargetFormat` [in]

The format of the render target surface, specified as a **D3DFORMAT** value. For more information, see the Direct3D documentation. You can also use a FOURCC code to specify a format that is not defined in the **D3DFORMAT** enumeration. See [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

### `pCount` [out]

Receives the number of elements returned in the *ppFormats* array.

### `pFormats` [out]

Receives an array of **D3DFORMAT** values. The caller must free the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). The array can contain both RGB and YUB pixel formats.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)