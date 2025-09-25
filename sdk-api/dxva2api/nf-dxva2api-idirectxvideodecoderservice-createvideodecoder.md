# IDirectXVideoDecoderService::CreateVideoDecoder

## Description

Creates a video decoder device.

## Parameters

### `Guid` [in]

GUID that specifies the decoder device to create. To get the available device GUIDs, call [IDirectXVideoDecoderService::GetDecoderDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoderservice-getdecoderdeviceguids).

### `pVideoDesc` [in]

Pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `pConfig` [in]

Pointer to a [DXVA2_ConfigPictureDecode](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_configpicturedecode) structure that specifies the decoder configuration.

### `ppDecoderRenderTargets` [in]

Pointer to an array of **IDirect3DSurface9** pointers containing pointers to the decoder render targets. To create these surfaces, call [IDirectXVideoAccelerationService::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoaccelerationservice-createsurface). Specify DXVA2_VideoDecoderRenderTarget for the *DxvaType* parameter.

### `NumRenderTargets` [in]

Size of the *ppDecoderRenderTargets* array. This value cannot be zero.

### `ppDecode` [out]

Receives a pointer to the decoder's [IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)