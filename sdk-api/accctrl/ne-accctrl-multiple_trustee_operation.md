# MULTIPLE_TRUSTEE_OPERATION enumeration

## Description

The **MULTIPLE_TRUSTEE_OPERATION** enumeration contains values that indicate whether a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure is an impersonation trustee.

## Constants

### `NO_MULTIPLE_TRUSTEE`

The trustee is not an impersonation trustee.

### `TRUSTEE_IS_IMPERSONATE`

The trustee is an impersonation trustee. The **pMultipleTrustee** member of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure points to a trustee for a server that can impersonate the client trustee.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)