## Description

Fetches general statistics about the diagnostic data records, filterable by producer.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `producerNames`

Type: **[PCWSTR\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
List of producer names to search for. A diagnostic data record that matches at least one of the producer names is included as a result in this search criteria. Use `nullptr` for this value to indicate no filter by producers.

### `producerNameCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of producer names in the list of producer names to search for. Use `0` for this value to indicate no filter by producers.

### `generalStats`

Type: **[DIAGNOSTIC_DATA_GENERAL_STATS\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_general_stats)**
This output parameter is a pointer to the resource that contains information about the general statistics for the diagnostic data records.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also