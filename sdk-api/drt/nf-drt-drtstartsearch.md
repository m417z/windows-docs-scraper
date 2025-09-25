# DrtStartSearch function

## Description

The **DrtStartSearch** function searches the DRT for a key using criteria specified in the [DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info) structure.

## Parameters

### `hDrt` [in]

The DRT handle returned by the [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen) function.

### `pKey` [in]

Pointer to the [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure containing the key.

### `pInfo` [in, optional]

Pointer to the [DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info) structure that specifies the properties of the search.

### `timeout`

Specifies the milliseconds until the search is stopped.

### `hEvent` [in]

Handle to the event that is signaled when the **DrtStartSearch** API finishes or an intermediate node is found.

### `pvContext` [in, optional]

Pointer to the context data passed to the application through the event.

### `hSearchContext` [out]

Handle used in the call to [DrtEndSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtendsearch).

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_HANDLE** | hDrt is an invalid handle or phKeyRegistration is an invalid handle |
| **E_INVALIDARG** | * *hSearchContext* is **NULL**.<br>* *pKey* is **NULL**<br>* The **pb** member of the [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure of *pKey* is **NULL**.<br>* *pInfo* was passed in, the minimum key is set inside *pInfo* for range search, but the maximum key is **NULL**.<br>* *pInfo* was passed in, the maximum key is set inside *pInfo* for range search, but the minimum key is **NULL**. |
| **DRT_E_INVALID_KEY_SIZE** | * The **cb** member of the [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure of *pKey* is not equal to 256 bits.<br>* *pInfo* was passed in, but the key size of the minimum key set inside *pInfo* is not equal to 256 bits.<br>* *pInfo* was passed in, but the key size of the maximum key set inside *pInfo* is not equal to 256 bits. |
| **DRT_E_INVALID_SEARCH_INFO** | *pInfo* was passed in but the **dwSize** of *pInfo* is not equal to size of the [DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info) structure. |
| **DRT_E_INVALID_MAX_ENDPOINTS** | *pInfo* was passed in but max endpoints (**cMaxEndpoints**) is set to 0 inside *pInfo* or *pInfo* was passed in but **cMaxEndpoints** is greater than 1 with **fAnyMatchInRange** set to **TRUE** |
| **DRT_E_INVALID_SEARCH_RANGE** | Min and max key values are equal, but target is different. |
| **DRT_E_FAULTED** | The DRT cloud is in the faulted state. |
| **E_OUTOFMEMORY** | The system is out of memory. |
| **E_UNEXPECTED** | The DRT is shutting down. |
| **E_FAIL** | An unexpected fatal error has occurred. |

## See also

[DRT_SEARCH_INFO](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_info)

[DrtContinueSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcontinuesearch)

[DrtEndSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtendsearch)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)