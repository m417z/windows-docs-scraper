# IProtocolHandlerSite::GetFilter

## Description

Retrieves the appropriate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) according to the supplied parameters.

## Parameters

### `pclsidObj` [in]

Type: **CLSID***

Pointer to the CLSID of the document type from the registry. This is used for items with embedded documents to indicate the appropriate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) to use for that embedded document.

### `pcwszContentType` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string that contains the type of the document. This is used to retrieve [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)**s** that are mapped according to MIME type.

### `pcwszExtension` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string that contains the file name extension, without the preceding period. This is used to retrieve [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) objects that are mapped according to the file name extension.

### `ppFilter` [out]

Type: **IFilter****

Receives the address of a pointer to the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) that the protocol handler uses.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method queries the Filter Host to identify the appropriate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) object to use for the URL item.

The choice of filter is based on the file name extension, a CLSID that identifies the file's content type in the registry, or on the MIME content type. You need to provide only one of the three parameters to this method. If you provide multiple parameters, they are tested in the following order: *pcwszContentType*, *pclsidObj*, *pcwszExtension*. The first valid parameter is used to select the appropriate [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter); the others are ignored.