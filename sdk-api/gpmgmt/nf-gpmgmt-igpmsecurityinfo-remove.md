## Description

Removes the permission specified in a given
[GPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission) object from the
[GPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) collection.

## Parameters

### `pPerm` [in]

Pointer to the **GPMPermission** object to remove from the collection.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

You cannot remove Inherited permissions. To determine if a permission is Inherited, see
[IGPMPermission Property Methods](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/igpmpermission-property-methods).

The method checks for the existence of the specified **GPMPermission** object, which is the pairing of a trustee (which is a user, computer, or security group) and a permission that applies to a single object, for example, to a GPO, SOM, or WMI filter. If the object exists in the collection, the method removes it.

If the permission specified for removal represents a higher level than the permission that exists for the trustee, the method removes the lower level permission. An example of this situation is specifying the removal of the permGPOEditSecurityAndDelete permission when the trustee has the lower permGPOEdit permission instead. In this case, the method removes the permGPOEdit permission.

If the permission specified for removal represents a lower level than the permission that exists for the trustee, the method returns S_FALSE.

On successful removal of a permission, the method updates all enumerators returned by the
[get__NewEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmsecurityinfo-get__newenum) method, even if a removal occurs during the enumeration of elements.

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission).

For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)