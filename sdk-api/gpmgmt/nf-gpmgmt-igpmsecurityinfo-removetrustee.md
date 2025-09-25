# IGPMSecurityInfo::RemoveTrustee

## Description

Removes all policy-related permissions for the specified trustee. A trustee is a user, computer, or security group that can be granted permissions on a GPO, SOM, or WMI filter.

## Parameters

### `bstrTrustee` [in]

Required. The name or SID of the trustee for which all permissions should be removed. Names are in Security Accounts Manager (SAM) compatible format (Exampledomain\Someone). Use null-terminated string.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

On successful removal of a permission, the method updates all enumerators returned by the
[get__NewEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmsecurityinfo-get__newenum) method, even if a removal occurs during the enumeration of elements.

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission). For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)