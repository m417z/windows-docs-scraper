# CIState function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Queries the state of the selected catalog.

## Parameters

### `pwcsCat` [in]

The catalog name, such as L"Web" or L"system".

### `pwcsMachine` [in]

The computer name on which the catalog is located, such as "." for the local computer or "RemoteServer1".

### `pCiState` [out]

A pointer to a [CI_STATE](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-ci_state) structure that receives the catalog state.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_INVALIDARG** | *pwcsCat* or *pCiState* is not a valid pointer, or the structure to which *pCiState* points is not large enough to hold the resulting state. |
| **CI_E_NO_CATALOG** | This function failed because the catalog was not found. |
| **CI_E_NOT_RUNNING** | The function failed because Indexing Service is not running. |
| **CI_E_TIMEOUT** | The function failed because Indexing Service is too busy to respond to the query. |

## Remarks

The [CI_STATE](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-ci_state) structure must be initialized (the **cbStruct** member must be correctly set) before calling the **CIState** function.

## See also

[CI_STATE](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-ci_state)

