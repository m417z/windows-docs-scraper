# ISearchCatalogManager::get_DataTimeout

## Description

Gets the data time-out value, in seconds, for data transactions between the indexer and the search filter host. This value is contained in a [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) structure.

## Parameters

### `pdwDataTimeout` [out, retval]

Type: **DWORD***

Receives a pointer to the [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) value for data transactions (the amount of time to wait for a data transaction).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The indexer expects the first chunk of a document to be received within the connection time-out interval and any subsequent chunks to be received within the data time-out interval. These time-out values help prevent filters and protocol handlers from failing or causing performance issues.