# DrtEndSearch function

## Description

The **DrtEndSearch** function cancels a search for a key in a DRT. This API can be called at any point after a search is issued.

## Parameters

### `hSearchContext` [in]

Handle to the search context to end. This parameter is returned from [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch).

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The *hSearchContext* handle is invalid. |
| **E_UNEXPECTED** | The DRT infrastructure is unaware of the requested search. |

## Remarks

Calling the **DrtEndSearch** function will stop the return of search results via [DRT_SEARCH_RESULT](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_result).

## See also

[DRT_SEARCH_RESULT](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_result)

[DrtContinueSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcontinuesearch)

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)