# IGPMGPO::IsACLConsistent

## Description

Checks for the consistency of ACLs between the Directory Service and the system volume folder (SysVol).

## Parameters

### `pvbConsistent` [out]

Value that indicates whether the
[access control lists (ACLs)](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) on the different parts of the GPO are consistent. If **VARIANT_TRUE**, they are consistent.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs or if the ACLs are not consistent.

### JScript

Value that indicates whether the ACLs are consistent. If **VARIANT_TRUE**, they are consistent. For more information, see the following Remarks section.

### VB

Value that indicates whether the ACLs are consistent. If **VARIANT_TRUE**, they are consistent. For more information, see the following Remarks section.

## Remarks

For more information about ACLs and the security model for controlling access to Windows objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)