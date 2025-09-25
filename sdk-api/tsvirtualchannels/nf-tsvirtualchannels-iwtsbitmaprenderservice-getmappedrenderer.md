# IWTSBitmapRenderService::GetMappedRenderer

## Description

Obtains the bitmap rendering object used to render media on the server.

## Parameters

### `mappingId` [in]

A 64-bit number that uniquely identifies the render mapping.

### `pMappedRendererCallback` [in]

The address of the caller's [IWTSBitmapRendererCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderercallback) interface.

### `ppMappedRenderer` [out]

The address of an [IWTSBitmapRenderer](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderer) interface pointer that receives the bitmap renderer. When you have finished using pointer, release it by calling the [IUnknown::Release()](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWTSBitmapRenderService](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderservice)