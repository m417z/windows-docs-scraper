## Description

Frees memory allocated for error reports referenced by HDIAGNOSTIC_REPORT_DATA handle.

## Parameters

### `hReport`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The handle to the resource that contains the set of error reports to be freed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For information the datatype DIAGNOSTIC_REPORT_DATA, see [**here**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_report_data)

## See also