# POLICY_AUDIT_SID_ARRAY structure

## Description

The **POLICY_AUDIT_SID_ARRAY** structure specifies an array of [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures that represent Windows users or groups.

## Members

### `UsersCount`

The number of [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures in the **UserSidArray** array.

### `UserSidArray.size_is`

### `UserSidArray.size_is.UsersCount`

### `UserSidArray`

A pointer to an array of pointers to [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures that specify Windows users or groups.

## See also

[AuditEnumeratePerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditenumerateperuserpolicy)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)