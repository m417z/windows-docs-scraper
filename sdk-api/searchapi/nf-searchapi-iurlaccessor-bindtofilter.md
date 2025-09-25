# IUrlAccessor::BindToFilter

## Description

Binds the item being processed to the appropriate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) and retrieves a pointer to the **IFilter**.

## Parameters

### `ppFilter` [out]

Type: **IFilter****

Receives the address of a pointer to the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) that can return metadata about the item being processed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method retrieves an [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) to enumerate the properties of the item associated with the specified URL, based on the protocol's information about that URL.

If the URL's content is also accessible from the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) returned by [IUrlAccessor::BindToStream](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-bindtostream), then a separate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) is invoked on the IStream to retrieve additional properties.