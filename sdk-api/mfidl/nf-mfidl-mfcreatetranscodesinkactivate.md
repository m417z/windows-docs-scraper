# MFCreateTranscodeSinkActivate function

## Description

Creates the transcode sink activation object.

The transcode sink activation object can be used to create any of the following file sinks:

* 3GP file sink
* MP3 file sink
* MP4 file sink

The transcode sink activation object exposes the [IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider) interface.

## Parameters

### `ppActivate` [out]

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. This interface is used to create the file sink instance from the activation object. Before doing so, query the returned pointer for the [IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider) interface and use that interface to initialize the object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)