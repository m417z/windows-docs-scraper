# IDirectXVideoProcessorService::GetVideoProcessorRenderTargets

## Description

Gets the render target formats that a video processor device supports. The list may include RGB and YUV formats.

## Parameters

### `VideoProcDeviceGuid` [in]

A GUID that identifies the video processor device.
To get the list of video processor GUIDs, call [IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessordeviceguids).

### `pVideoDesc` [in]

A pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `pCount` [out]

Receives the number of formats.

### `pFormats` [out]

Receives an array of formats, specified as **D3DFORMAT** values. The size of the array is retrieved in the *pCount* parameter. The method allocates the memory for the array. The caller must free the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)