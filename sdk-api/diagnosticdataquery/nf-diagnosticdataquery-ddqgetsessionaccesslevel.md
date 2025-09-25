## Description

Returns the data access level of the current Diagnostic Data Query session.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `accessLevel`

Type: **[DdqAccessLevel\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ne-diagnosticdataquerytypes-ddqaccesslevel)**
This output parameter is the pointer to the access level for this session.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also