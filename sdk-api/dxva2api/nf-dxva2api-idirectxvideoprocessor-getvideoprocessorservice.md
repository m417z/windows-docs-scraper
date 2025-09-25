# IDirectXVideoProcessor::GetVideoProcessorService

## Description

Retrieves the DirectX Video Acceleration (DXVA) video processor service that created this video processor device.

## Parameters

### `ppService` [out]

Receives a pointer to [IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)