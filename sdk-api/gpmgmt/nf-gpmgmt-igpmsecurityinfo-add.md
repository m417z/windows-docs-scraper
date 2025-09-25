## Description

Adds the permission specified in a
[GPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission) object to the
[GPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) collection. You can add a permission that is above the level of existing permissions. For more information about restrictions that apply, see the following Remarks section.

## Parameters

### `pPerm` [in]

Pointer to the **GPMPermission** object to add to the collection.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

A trustee is a user, computer, or security group that can be granted permissions on a GPO, SOM, or WMI filter.

Note that there can be some overlap of the permission levels that apply to a given object. Instances include the following:

* permGPOEditSecurity is a superset of permGPOEdit, which is a superset of permGPORead
* permGPOApply is a superset of permGPORead
* permWMIFilterFullControl is a superset of permWMIFilterEdit
* permSOMWMIFullControl is a superset of permSOMWMICreate

If a permission that you are adding for a trustee overlaps (as defined above) with an existing permission that already exists on the object, the following rules apply:

1. If there is an Inherited permission on the object, you cannot add a higher level permission for the user. This is because an Inherited permission cannot be modified. The permission must first be removed from the parent container before a change can be made to the Inherited permission.
2. If there is a Denied permission on the object, you cannot add a higher level permission to the existing permission for the user.
3. If there is a permission that is explicitly set on the object, adding a lower level permission does not change the user's permissions. In addition, the method returns S_FALSE, which can be tested for by the calling application.
4. If there is a permission that is explicitly set on the object, adding a higher level permission changes the user's permissions.
5. Because permGPORead is a subset of permGPOEdit and permGPOApply, permGPORead can be removed only if both permGPOEdit and permGPOApply are removed.
6. If the current permission is not inheritable, and the permission you are adding sets the Inheritable property to TRUE, then the permission is changed to be an inheritable one.
7. If the current permission is inheritable, and the permission you are adding sets the Inheritable property to FALSE, the method returns S_FALSE.

Note that you cannot add Denied, Inherited, or custom permissions using the GPMC, but you can add Inheritable permissions. You can delete Denied and custom permissions. If you attempt to add a Denied permission, it results in an error. Custom permissions are those that do not match any of the permission levels defined by the GPMC. For example, if a trustee is granted the "Apply" ACE for a GPO, but not the "Read" ACE, the permission is a custom permission. To determine if a permission is Denied or Inherited you can call the
[IGPMPermission Property Methods](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/igpmpermission-property-methods).

For more information about predefined policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission). For information about permission categories and levels, see
[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo).

When adding permissions on a GPO, the value of the Inheritable property is ignored and set to **TRUE**. This is because all GPO permissions should be inheritable to the User and Computer child containers in the directory service and to subdirectories in the system volume folder (SysVol). When adding permissions on WMI filters, the value of the Inheritable property is always set to **FALSE**.

For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)