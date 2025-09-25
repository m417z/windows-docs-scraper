# ACCESS_MODE enumeration

## Description

The **ACCESS_MODE** enumeration contains values that indicate how the access rights in an
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure apply to the trustee. Functions such as
[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) and
[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla) use these values to set or retrieve information in an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

## Constants

### `NOT_USED_ACCESS`

Value not used.

### `GRANT_ACCESS`

Indicates an
[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) structure. The new ACE combines the specified rights with any existing allowed or denied rights of the trustee.

### `SET_ACCESS`

Indicates an [ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) structure that allows the specified rights.

On input, this value discards any existing access control information for the trustee.

### `DENY_ACCESS`

Indicates an
[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace) structure that denies the specified rights.

On input, this value denies the specified rights in addition to any currently denied rights of the trustee.

### `REVOKE_ACCESS`

Indicates that all existing [ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) or
[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structures for the specified trustee are removed.

### `SET_AUDIT_SUCCESS`

Indicates a [SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure that generates audit messages for successful attempts to use the specified access rights.

On input, this value combines the specified rights with any existing audited access rights for the trustee.

### `SET_AUDIT_FAILURE`

Indicates a
[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure that generates audit messages for failed attempts to use the specified access rights.

On input, this value combines the specified rights with any existing audited access rights for the trustee.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)