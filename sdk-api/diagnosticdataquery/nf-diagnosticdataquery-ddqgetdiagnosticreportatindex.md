## Description

Fetches an error report and its information at the specified index in the resource pointed to by the HDIAGNOSTIC_REPORT_DATA handle.

## Parameters

### `hReport`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource with the set of problem reports.

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The index of the error report to fetch.

### `report`

Type: **[DIAGNOSTIC_DATA_REPORT_DATA\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_report_data)**
This output parameter is a pointer to the resource that contains information about the fetched diagnostic report.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also