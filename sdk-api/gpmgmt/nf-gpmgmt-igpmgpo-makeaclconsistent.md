# IGPMGPO::MakeACLConsistent

## Description

Makes [ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) consistent on the Directory Service and the system volume folder (SysVol) of the GPO. [IsACLConsistent](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-isaclconsistent) can be used to check for consistency of ACLs between the Directory Service and system volume folder (SysVol).

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

For more information about ACLs and the security model for controlling access to Windows objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMGPO::IsACLConsistent](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-isaclconsistent)