## Description

Fetches the number (size) of error reports in the resource pointed to by HDIAGNOSTIC_REPORT_DATA handle.

## Parameters

### `hReport`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Handle to the resource that contains the set of error reports.

### `reportCount`

Type: **[UINT32\*](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Pointer to the number of error reports.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also