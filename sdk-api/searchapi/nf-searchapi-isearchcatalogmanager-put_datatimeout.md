# ISearchCatalogManager::put_DataTimeout

## Description

Sets the time-out value for data transactions between the indexer and the search filter host. This information is stored in the [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) structure and is measured in seconds.

## Parameters

### `dwDataTimeout` [in]

Type: **DWORD**

The number of seconds that the indexer will wait between chunks of data.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The indexer expects the first chunk of the document to be received within the connection time-out interval and any subsequent chunks to be received within the data time-out interval. These time-out values help prevent filters and protocol handlers from failing or causing performance issues.