## Description

Fetches the filtered event transcript Diagnostic Data record stats. The filtering on statistics returned is performed using the input parameter, DIAGNOSTIC_DATA_SEARCH_CRITERIA filter. The record state describes how many records matching the search criteria are available, and returns parameters used for further querying of data. One of the uses of this API is to check if there have been changes since the last time data was queried for. A change in the output parameters indicate a change in state of the event transcript record state.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `searchCriteria`

Type: **[DIAGNOSTIC_DATA_SEARCH_CRITERIA\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_search_criteria)**
Pointer to the resource that contains the search criteria for this operation. This resource contains criteria such as producers, categories, and tags.

### `recordCount`

Type: **[UINT32\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is the pointer to the number of records that match on the search criteria.

### `minRowId`

Type: **[INT64\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is the pointer to the minimum row id of the record that matches on the search criteria.

### `maxRowId`

Type: **[INT64\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is the pointer to the maximum row id of the record that matches on the search criteria.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also