# IDirectXVideoProcessor::GetVideoProcessorCaps

## Description

Retrieves the capabilities of the video processor device.

## Parameters

### `pCaps` [out]

Pointer to a [DXVA2_VideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessorcaps) structure that receives the video processor capabilities.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)