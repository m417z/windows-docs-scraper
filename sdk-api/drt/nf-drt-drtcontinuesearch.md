# DrtContinueSearch function

## Description

The **DrtContinueSearch** function continues an iterative search for a key.This function is used only when the **fIterative** flag is set to 'true' in the associated [DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info) structure. Call this after getting a **DRT_MATCH_INTERMEDIATE** search result.

## Parameters

### `hSearchContext` [in]

Handle to the search context to close. This parameter is returned by the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) API.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The *hSearchContext* handle is invalid. |
| **E_UNEXPECTED** | This search is not an iterative search. |

## See also

[DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info)

[DrtEndSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtendsearch)

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)