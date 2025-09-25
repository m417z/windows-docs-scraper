# DrtGetSearchResultSize function

## Description

The **DrtGetSearchResultSize** function returns the size of the next available search result.

## Parameters

### `hSearchContext` [in]

Handle to the search context to close. This parameter is returned by the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) function.

### `pulSearchResultSize` [out]

Holds the size of the next available search result.

## Return value

Returns S_OK if the function succeeds. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pulSearchResultSize* is **NULL**. |
| **E_HANDLE** | *hSearchContext* is an invalid handle. |
| **DRT_E_FAULTED** | The DRT cloud is in the faulted state. |
| **DRT_E_NO_MORE** | There are no more results to return. |
| **DRT_E_TIMEOUT** | The search failed because it timed out. |
| **DRT_E_SEARCH_IN_PROGRESS** | The search is still in progress. |

## Remarks

The application will receive S_OK and continue to loop using the **DrtGetSearchResultSize** and [DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult) functions as long as the queue contains the search results. When the queue is empty the **DrtGetSearchResult** function will return DRT_E_SEARCH_IN_PROGRESS or DRT_E_NO_MORE.

## See also

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)