# IGPMConstants::get_SecurityFlags

## Description

Retrieves the value of the
**SecurityFlags** property, which represents the portion of the security descriptor to retrieve or set for a GPO. You can pass the returned value in the *ulFlags* parameter to the
[IGPMGPO::GetSecurityDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-getsecuritydescriptor) and
[IGPMGPO::SetSecurityDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-setsecuritydescriptor) methods.

This property is read-only.

## Parameters

## Remarks

For more information about access control lists (ACLs) and the security model for controlling access to objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

## See also

[IGPMConstants](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmconstants)