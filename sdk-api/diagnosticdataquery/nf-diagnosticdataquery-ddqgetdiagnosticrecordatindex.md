## Description

Fetches diagnostic data record information at the specified index in the resource pointed to by the HDIAGNOSTIC_DATA_RECORD handle.

## Parameters

### `hRecord`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of DIAGNOSTIC_DATA_RECORD items.

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Index of the record to be fetched.

### `record`

Type: **[DIAGNOSTIC_DATA_RECORD\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_record)**
This output parameter is a pointer to the record at the specified index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also