## Description

Fetches the payload text for the event record specified by rowId.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `rowId`

Type: **[INT64](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The row id for the event record of interest.

### `payload`

Type: **[PCWSTR\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the payload text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also