# COMSD enumeration

## Description

Determines the type of COM security descriptor to get when calling [CoGetSystemSecurityPermissions](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetsystemsecuritypermissions).

## Constants

### `SD_LAUNCHPERMISSIONS:0`

Machine-wide launch permissions.

### `SD_ACCESSPERMISSIONS:1`

Machine-wide access permissions.

### `SD_LAUNCHRESTRICTIONS:2`

Machine-wide launch limits.

### `SD_ACCESSRESTRICTIONS:3`

Machine-wide access limits.

## See also

[CoGetSystemSecurityPermissions](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetsystemsecuritypermissions)