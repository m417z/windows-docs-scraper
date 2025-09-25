# ISearchCatalogManager::ReindexMatchingURLs

## Description

Reindexes all items that match the provided pattern. This method was not implemented prior to Windows 7.

## Parameters

### `pszPattern` [in]

Type: **LPCWSTR**

A pointer to the pattern to be matched for reindexing. The pattern can be a standard pattern such as `*.pdf` or a pattern in the form of a URL such as `file:///c:\MyStuff\*.pdf`.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is fully implemented for Windows 7.