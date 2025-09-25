# BindIFilterFromStream function

## Description

[Indexing Service is unsupported as of Windows XP. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.]

Retrieves the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface pointer for the specified storage object. This is especially useful when filtering the contents of a document and processing embedded OLE objects accessible through their **IStream** interfaces.

## Parameters

### `pStm` [in]

A pointer to the **IStream** interface to be used to access the file.

### `pUnkOuter` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the aggregate in which this stream object exists.

### `ppIUnk` [out]

A pointer to an output variable that receives the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface pointer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_ACCESSDENIED** | The function was denied access to the path of the storage object. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

This function is not a full implementation of a COM persistent handler.

## See also

[BindIFilterFromStorage](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-bindifilterfromstorage)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)

[LoadIFilter](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-loadifilter)