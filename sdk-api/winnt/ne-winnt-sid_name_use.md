# SID_NAME_USE enumeration

## Description

The **SID_NAME_USE** enumeration contains values that specify the type of a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Constants

### `SidTypeUser:1`

A user SID.

### `SidTypeGroup`

A group SID.

### `SidTypeDomain`

A domain SID.

### `SidTypeAlias`

An alias SID.

### `SidTypeWellKnownGroup`

A SID for a well-known group.

### `SidTypeDeletedAccount`

A SID for a deleted account.

### `SidTypeInvalid`

A SID that is not valid.

### `SidTypeUnknown`

A SID of unknown type.

### `SidTypeComputer`

A SID for a computer.

### `SidTypeLabel`

A mandatory integrity label SID.

### `SidTypeLogonSession`

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida)