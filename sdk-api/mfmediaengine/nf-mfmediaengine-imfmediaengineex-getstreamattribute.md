# IMFMediaEngineEx::GetStreamAttribute

## Description

Gets a stream-level attribute from the media resource.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. To get the number of streams, call [IMFMediaEngineEx::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getnumberofstreams).

### `guidMFAttribute` [in]

The attribute to query. Possible values are listed in the following topics:

* [Stream Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/stream-descriptor-attributes)
* [Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes)

### `pvValue` [out]

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) that receives the value. The method fills the **PROPVARIANT** with a copy of the stored value. Call [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear) to free the memory allocated by the method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)