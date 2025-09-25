# IMFTranscodeSinkInfoProvider::SetOutputByteStream

## Description

Sets an output byte stream for the transcode media sink.

## Parameters

### `pByteStreamActivate` [in]

A pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of a byte-stream activation object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method to provide a writable byte stream
that will receive the transcoded data.

Alternatively, you can provide the name of an output file, by calling [IMFTranscodeSinkInfoProvider::SetOutputFile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-setoutputfile). These two methods are mutually exclusive.

The *pByteStreamActivate* parameter must specify an activation object that creates a writable byte stream. Internally, the transcode media sink calls [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) to create the byte stream, as follows:

``` syntax
IMFByteStream *pByteStream = NULL;

HRESULT hr = pByteStreamActivate->ActivateObject(IID_IMFByteStream, (void**)&pByteStream);
```

Currently, Microsoft Media Foundation does not provide any byte-stream activation objects. To use this method, an application must provide a custom implementation of [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate).

## See also

[IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider)