## Description

Creates a Diagnostic Data Query API session handle to be used to uniquely identify a Diagnostic Data Query session.

## Parameters

### `accessLevel`

Type: **[DdqAccessLevel](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ne-diagnosticdataquerytypes-ddqaccesslevel)**
The access level desired for this session.

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a handle to the created Diagnostic Data Query session.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also