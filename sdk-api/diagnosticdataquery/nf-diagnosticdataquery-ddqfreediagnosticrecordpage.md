## Description

Frees memory allocated for the diagnostic record page referenced by HDIAGNOSTIC_RECORD handle.

## Parameters

### `hRecord`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the set of diagnostic records to be freed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more information about the DIAGNOSTIC_RECORD datatype, see [**here**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_record).

## See also