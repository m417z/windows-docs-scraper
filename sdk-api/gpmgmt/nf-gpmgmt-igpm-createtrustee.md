# IGPM::CreateTrustee

## Description

Creates and returns a [GPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee) from which you can retrieve information about a trustee. A trustee is a user, computer, or security group that can be granted permissions on a Group Policy object (GPO), scope of management (SOM), or Windows Management Instrumentation (WMI) filter.

## Parameters

### `bstrTrustee` [in]

Required. Trustee name or the security identifier (SID). Names are in a format that is compatible with Security Accounts Manager (SAM), such as *Exampledomain*\*Someone*.

### `ppIGPMTrustee` [out]

Address of a pointer to the
[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee) object.

### VB

Returns a reference to a [GPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee) object.

## Remarks

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission). For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)