## Description

Fetches number (size) of diagnostic records in the resource pointed to by the HDIAGNOSTIC_DATA_RECORD handle.

## Parameters

### `hRecord`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the DIAGNOSTIC_DATA_RECORD list.

### `recordCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Number of items in the DIAGNOSTIC_DATA_RECORD list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more information about diagnostic data record data type, see [**DIAGNOSTIC_DATA_RECORD**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_record)

## See also