# IDirectXVideoProcessorService::GetFilterPropertyRange

## Description

Retrieves the range of values for an image filter supported by a video processor device.

## Parameters

### `VideoProcDeviceGuid` [in]

A GUID that identifies the video processor device.
To get the list of video processor GUIDs, call [IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessordeviceguids).

### `pVideoDesc` [in]

A pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `RenderTargetFormat` [in]

The format of the render target surface, specified as a **D3DFORMAT** value. For more information, see the Direct3D documentation. You can also use a FOURCC code to specify a format that is not defined in the **D3DFORMAT** enumeration. See [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

### `FilterSetting` [in]

The filter setting to query. See [DXVA Image Filter Settings](https://learn.microsoft.com/windows/desktop/medfound/dxva-image-filter-settings).

### `pRange` [out]

A pointer to a [DXVA2_ValueRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_valuerange) structure that receives range of values for the image filter setting specified in *FilterSetting*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)