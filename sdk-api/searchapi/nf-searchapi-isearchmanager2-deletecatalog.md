# ISearchManager2::DeleteCatalog

## Description

Deletes an existing catalog and all associated indexed data from the Windows Search indexer.

## Parameters

### `pszCatalog` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of catalog to delete. The catalog must at some prior time have been created with a call to CreateCatalog().

## Return value

Type: **HRESULT**

HRESULT indicating status of operation:

| Return code | Description |
| --- | --- |
| **S_OK** | Catalog previously existed and has now been successfully deleted. |
| **S_FALSE** | Catalog did not previously existed, no change. |

FAILED HRESULT: Failure deleting catalog or invalid arguments passed.

## See also

[ISearchManager2](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchmanager2)