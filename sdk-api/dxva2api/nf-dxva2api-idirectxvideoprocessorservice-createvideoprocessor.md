# IDirectXVideoProcessorService::CreateVideoProcessor

## Description

Creates a video processor device.

## Parameters

### `VideoProcDeviceGuid` [in]

A GUID that specifies the video processor to create.
To get the list of video processor GUIDs, call [IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessordeviceguids).

### `pVideoDesc` [in]

A pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `RenderTargetFormat` [in]

The format of the render target surface, specified as a **D3DFORMAT** value. For more information, see the Direct3D documentation. You can also use a FOURCC code to specify a format that is not defined in the **D3DFORMAT** enumeration. See [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

### `MaxNumSubStreams` [in]

The maximum number of substreams that will be used with this device.

### `ppVidProcess` [out]

Receives a pointer to the video processor's [IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)