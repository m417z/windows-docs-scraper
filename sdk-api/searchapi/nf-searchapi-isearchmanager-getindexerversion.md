# ISearchManager::GetIndexerVersion

## Description

Retrieves the version of the current indexer in two chunks: the major version signifier and the minor version signifier.

## Parameters

### `pdwMajor` [out]

Type: **DWORD***

Receives the major version signifier (the number to the left of the dot).

### `pdwMinor` [out]

Type: **DWORD***

Receives the minor version signifier (the number to the right of the dot).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.