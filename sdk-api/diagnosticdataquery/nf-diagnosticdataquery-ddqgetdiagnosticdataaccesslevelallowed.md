## Description

Returns the highest available data access level for the API caller. This can be NoData, CurrentUserData or AllUserData.

## Parameters

### `accessLevel`

Type: **[DdqAccessLevel\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ne-diagnosticdataquerytypes-ddqaccesslevel)**
This output parameter is a pointer to the highest access level available for the API caller.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also