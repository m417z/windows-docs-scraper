# IDirectXVideoProcessor::GetCreationParameters

## Description

Retrieves the parameters that were used to create this device.

## Parameters

### `pDeviceGuid` [out]

Receives the device GUID. This parameter can be **NULL**.

### `pVideoDesc` [out]

Pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure allocated by the caller. The method fills the structure with a description of the video format. This parameter can be **NULL**.

### `pRenderTargetFormat` [out]

Receives the render target format, specified as a **D3DFORMAT** value. For more information, see the Direct3D documentation. This parameter can be **NULL**.

### `pMaxNumSubStreams` [out]

Receives the maximum number of streams supported by the device. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. At least one parameter must be non-**NULL**. |

## Remarks

You can set any parameter to **NULL** if you are not interested in the result. At least one parameter must be non-**NULL**.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)