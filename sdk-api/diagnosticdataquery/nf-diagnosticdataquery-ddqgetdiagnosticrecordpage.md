## Description

Fetches a page (batch) of filtered records. The filtering on records returned is performed internally using the input parameters DIAGNOSTIC_DATA_SEARCH_CRITERIA searchCriteria, pageRecordCount, offset and baseRowId.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `searchCriteria`

Type: **[DIAGNOSTIC_DATA_SEARCH_CRITERIA\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_search_criteria)**
Pointer to the resource that contains the search criteria for this operation. This resource contains criteria such as producers, categories, and tags.

### `offset`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Filters results by returning records with rowId that start at the offset from the baseRowId.

### `pageRecordCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of records in a desired record page

### `baseRowId`

Type: **[INT64](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Filters out new records by returning only records with rowId value less than or equal to baseRowId (this is useful if querying code wants to limit results to only events that were available at the time of DdqGetDiagnosticRecordStats call. The maxRowId parameter can be used as baseRowId). No filtering is applied if –1 is passed for baseRowId.

### `hRecord`

Type: **[HANDLE\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the handle for the resource that contains the list of matching records.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also