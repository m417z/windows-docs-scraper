# IUrlAccessor::GetDocFormat

## Description

Gets the document format, represented as a Multipurpose Internet Mail Extensions (MIME) string.

## Parameters

### `wszDocFormat` [out]

Type: **WCHAR[]**

Receives a pointer to a null-terminated Unicode string containing the MIME type for the current item.

### `dwSize` [in]

Type: **DWORD**

Size of *wszDocFormat* in **TCHAR****s**.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of **TCHAR****s** written to *wszDocFormat*, not including the terminating **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *wszDocFormat* is used to identify the correct [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) for the stream returned by [IUrlAccessor::BindToStream](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-bindtostream). Implement this method when the URL item is supposed to have a different association than is indicated by the file name extension or content type. For example, if .doc items are not associated with Microsoft Word, this method should return the [CLSID Key](https://learn.microsoft.com/windows/desktop/com/clsid-key-hklm) key of the appropriate document source.

If you do not provide an implementation of this method or the [IUrlAccessor::GetCLSID](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-getclsid) method, the filter host uses the out parameters from [IUrlAccessor::GetFileName](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-getfilename) to determine the Multipurpose Internet Mail Extensions (MIME) content type.