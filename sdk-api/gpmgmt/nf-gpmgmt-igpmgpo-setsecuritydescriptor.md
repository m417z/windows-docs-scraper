## Description

Sets the security descriptor for the GPO. The method replaces the existing security descriptor.

## Parameters

### `lFlags` [in]

Specifies a set of bit flags. Use this parameter to specify the parts of the security descriptor to set.

#### OWNER_SECURITY_INFORMATION (1)

Owner identifier of the object.

#### GROUP_SECURITY_INFORMATION (2)

Primary group identifier.

#### DACL_SECURITY_INFORMATION (4)

Discretionary ACL of the object.

#### SACL_SECURITY_INFORMATION (8)

System ACL of the object.

### `pSD` [in]

The security descriptor to set.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

For more information about ACLs and the security model for controlling access to Windows objects, see the
[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) topic .

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)