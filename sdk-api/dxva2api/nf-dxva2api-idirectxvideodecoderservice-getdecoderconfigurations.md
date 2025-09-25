# IDirectXVideoDecoderService::GetDecoderConfigurations

## Description

Gets the configurations that are available for a decoder device.

## Parameters

### `Guid` [in]

A GUID that identifies the decoder device. To get the available device GUIDs, call [IDirectXVideoDecoderService::GetDecoderDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoderservice-getdecoderdeviceguids).

### `pVideoDesc` [in]

A pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `pReserved` [in]

Reserved. Set to **NULL**.

### `pCount` [out]

Receives the number of configurations.

### `ppConfigs` [out]

Receives an array of [DXVA2_ConfigPictureDecode](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_configpicturedecode) structures. The size of the array is retrieved in the *pCount* parameter. The caller must free the memory for the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL** if you simply want the number of configurations (returned in *pCount*) but not the GUIDs.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA2_ConfigPictureDecode](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_configpicturedecode)

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)