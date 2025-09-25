# ISearchCatalogManager::get_ConnectTimeout

## Description

Gets the connection time-out value for connecting to a store for indexing.

## Parameters

### `pdwConnectTimeout` [out, retval]

Type: **DWORD***

Receives a pointer to the time-out value, in seconds, from the [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The indexer expects the first chunk of the document to be received within the connection time-out interval and any subsequent chunks to be received within the data time-out interval. These time-out values help prevent filters and protocol handlers from failing or causing performance issues.