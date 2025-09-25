# TRUSTEE_TYPE enumeration

## Description

The **TRUSTEE_TYPE** enumeration contains values that indicate the type of trustee identified by a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Constants

### `TRUSTEE_IS_UNKNOWN`

The trustee type is unknown, but it may be valid.

### `TRUSTEE_IS_USER`

Indicates a user.

### `TRUSTEE_IS_GROUP`

Indicates a group.

### `TRUSTEE_IS_DOMAIN`

Indicates a domain.

### `TRUSTEE_IS_ALIAS`

Indicates an alias.

### `TRUSTEE_IS_WELL_KNOWN_GROUP`

Indicates a
[well-known group](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

### `TRUSTEE_IS_DELETED`

Indicates a deleted account.

### `TRUSTEE_IS_INVALID`

Indicates a trustee type that is not valid.

### `TRUSTEE_IS_COMPUTER`

Indicates a computer.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)