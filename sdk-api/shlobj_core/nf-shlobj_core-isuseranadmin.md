# IsUserAnAdmin function

## Description

[**IsUserAnAdmin** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Tests whether the current user is a member of the Administrator's group.

## Return value

Type: **BOOL**

Returns **TRUE** if the user is a member of the Administrator's group; otherwise, **FALSE**.

## Remarks

This function is a wrapper for [CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership). It is recommended to call that function directly to determine Administrator group status rather than calling **IsUserAnAdmin**.

## See also

[CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership)