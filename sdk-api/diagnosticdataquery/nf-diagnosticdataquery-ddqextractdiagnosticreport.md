## Description

Used for retrieving Windows Error Reporting reports, this API extracts cabs to destination path specified. If the error report does not contain any cabs, no work is performed.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the current Diagnostic Data Query session

### `reportStoreType`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The type of report store to extract from. See remarks.

### `reportKey`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A pointer to the report key string. See remarks.

### `destinationPath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The destination path the report should be extracted to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For report store types, see the [**WER APIs**](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werstoreopen).
For report keys, see the [**WER APIs**](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werstoregetnextreportkey).

## See also