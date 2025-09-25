# IUrlAccessor::BindToStream

## Description

Binds the item being processed to an [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) data stream and retrieves a pointer to that stream.

## Parameters

### `ppStream` [out]

Type: **IStream****

Receives the address of a pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that contains the item represented by the URL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Using the information returned by the [IUrlAccessor::GetFileName](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-getfilename), [IUrlAccessor::GetCLSID](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-getclsid), and [IUrlAccessor::GetDocFormat](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-getdocformat) methods, the appropriate content [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) object is created and passed to this stream by the IPersistStream interface.