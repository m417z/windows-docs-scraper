# DrtGetSearchResult function

## Description

The **DrtGetSearchResult** function allows the caller to retrieve the search result(s).

## Parameters

### `hSearchContext` [in]

Handle to the search context to close. This parameter is returned by the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) function.

### `ulSearchResultSize` [out]

Pointer to the [DRT_SEARCH_RESULT](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_result) structure containing the search result.

### `pSearchResult`

Receives a pointer to a DRT_SEARCH_RESULT structure containing the search results.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *ulSearchPathSize* is less than the size of [DRT_SEARCH_RESULT](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_result). |
| **E_HANDLE** | *hSearchContext* is an invalid handle. |
| **DRT_E_FAULTED** | the DRT cloud is in the faulted state. |
| **DRT_E_INSUFFICIENT_BUFFER** | The provided buffer is insufficient in size to contain the search result. |
| **DRT_E_NO_MORE** | There are no more results to return. |
| **DRT_E_TIMEOUT** | The search failed because it timed out. |
| **DRT_E_SEARCH_IN_PROGRESS** | The search is currently in progress. |

## See also

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)