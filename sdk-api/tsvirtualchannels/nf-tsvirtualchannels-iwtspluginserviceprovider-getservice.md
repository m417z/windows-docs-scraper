# IWTSPluginServiceProvider::GetService

## Description

Obtains the specified service.

## Parameters

### `ServiceId` [in]

Specifies the service to retrieve. This can be the following values.

#### RDCLIENT_BITMAP_RENDER_SERVICE

Identifies the bitmap rendering service. The *ppunkObject* parameter receives an [IWTSBitmapRenderService](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderservice) interface pointer.

### `ppunkObject` [out]

The address of a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface that receives the service object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWTSPluginServiceProvider](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtspluginserviceprovider)