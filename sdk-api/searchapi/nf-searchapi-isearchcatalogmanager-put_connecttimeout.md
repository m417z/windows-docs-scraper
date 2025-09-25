# ISearchCatalogManager::put_ConnectTimeout

## Description

Sets the connection time-out value in the [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) structure, in seconds.

## Parameters

### `dwConnectTimeout` [in]

Type: **DWORD**

The number of seconds to wait for a connection response.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The indexer expects the first chunk of the document to be received within the connection time-out interval and any subsequent chunks to be received within the data time-out interval. These time-out values help prevent filters and protocol handlers from failing or causing performance issues.