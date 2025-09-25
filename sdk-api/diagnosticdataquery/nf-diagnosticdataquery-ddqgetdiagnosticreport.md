## Description

Fetches error reports uploaded or enqueued for upload from this PC via HDIAGNOSTIC_REPORT_DATA handle.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `reportStoreType`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The type of report store to extract from. See remarks.

### `hReport`

Type: **[HANDLE\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the handle for the resource that contains the known set of problem reports.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For report store types, see the [**WER APIs**](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werstoreopen).

## See also