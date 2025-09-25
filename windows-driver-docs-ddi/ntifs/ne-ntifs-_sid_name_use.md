# _SID_NAME_USE enumeration

## Description

The SID_NAME_USE enumeration type contains values that specify the type of a security identifier (SID).

## Constants

### `SidTypeUser`

This value indicates a user SID.

### `SidTypeGroup`

This value indicates a group SID.

### `SidTypeDomain`

This value indicates a domain SID.

### `SidTypeAlias`

This value indicates an alias SID.

### `SidTypeWellKnownGroup`

This value indicates an SID for a well-known group.

### `SidTypeDeletedAccount`

This value indicates a SID for a deleted account.

### `SidTypeInvalid`

This value indicates an invalid SID.

### `SidTypeUnknown`

This value indicates an unknown SID type.

### `SidTypeComputer`

This value indicates a SID for a computer.

### `SidTypeLabel`

### `SidTypeLogonSession`

## Remarks

This enumeration type is the same as the Win32 SID_NAME_USE enumeration type defined in *winnt.h* used by the Win32 **LookupAccountName** and **LookupAccountSid** functions.

## See also

[**SecLookupAccountSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupaccountsid)

[**SecLookupAccountName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupaccountname)