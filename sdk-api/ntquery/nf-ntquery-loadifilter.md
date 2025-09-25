# LoadIFilter function

## Description

[Indexing Service is unsupported as of Windows XP. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.]

Retrieves [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) from path name for object.

## Parameters

### `pwcsPath`

A pointer to the full path of an object for which an [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface pointer is to be returned. The path can include a full filename or only the file name extension; for example, ".ext".

### `pUnkOuter` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the aggregate in which this storage object exists.

### `ppIUnk` [out]

A pointer to a variable that receives the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface pointer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_ACCESSDENIED** | The function was denied access to the filter file. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## See also

[BindIFilterFromStorage](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-bindifilterfromstorage)

[BindIFilterFromStream](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-bindifilterfromstream)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)