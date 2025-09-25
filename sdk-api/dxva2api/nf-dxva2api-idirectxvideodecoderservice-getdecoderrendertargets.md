# IDirectXVideoDecoderService::GetDecoderRenderTargets

## Description

Retrieves the supported render targets for a specified decoder device.

## Parameters

### `Guid` [in]

GUID that identifies the decoder device. To get the available device GUIDs, call [IDirectXVideoDecoderService::GetDecoderDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoderservice-getdecoderdeviceguids).

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

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)