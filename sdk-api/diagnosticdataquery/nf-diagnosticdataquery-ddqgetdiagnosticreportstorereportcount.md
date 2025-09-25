## Description

Fetches the number (size) of reports stored in the requested store.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `reportStoreType`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The type of report store to extract from. See remarks.

### `reportCount`

Type: **[UINT32\*](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Pointer to the number of error reports.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also