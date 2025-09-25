# DXVA2CreateVideoService function

## Description

Creates a DirectX Video Acceleration (DXVA) services object. Call this function if your application uses DXVA directly, without using DirectShow or Media Foundation.

## Parameters

### `pDD`

A pointer to the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface of a Direct3D device.

### `riid`

The interface identifier (IID) of the requested interface. Any of the following interfaces might be supported by the Direct3D device:

* [IDirectXVideoAccelerationService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoaccelerationservice)
* [IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)
* [IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)

### `ppService`

Receives a pointer to the interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)