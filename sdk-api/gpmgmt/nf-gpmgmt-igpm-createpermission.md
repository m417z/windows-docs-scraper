# IGPM::CreatePermission

## Description

Creates and returns an interface or object that represents the trustee (such as a user, computer or security group) and permission that applies to a single object; for example, to a GPO, SOM or a WMI filter.

## Parameters

### `bstrTrustee` [in]

Required. Trustee name. This parameter can be a string that specifies the security identifier (SID) of the account. This parameter can also be a Security Accounts Manager (SAM) account name, such as "Engineering\JSmith".

### `perm` [in]

Required. Permission to use for the trustee. The following policy-related permissions are supported. Note that each permission value represents one or more
[access rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks) that apply to the GPO.

The following GPO permissions are supported.

#### permGPOApply

The trustee can apply the GPO. This value corresponds to the READ and APPLY Group Policy access rights being set to Allow for a user.

#### permGPORead

The trustee can read the GPO. This value corresponds to the READ Group Policy access right being set to Allow for a user.

#### permGPOEdit

The trustee can read and edit the policy settings for the GPO. This value corresponds to the READ, WRITE, CREATE CHILD OBJECT, and DELETE CHILD OBJECT Group Policy access rights being set to Allow for a user.

#### permGPOEditSecurityAndDelete

The trustee can read, edit and delete the permissions for the GPO. This value corresponds to the Group Policy access rights specified by **permGPOEdit** plus the DELETE, MODIFY PERMISSIONS, and MODIFY OWNER access rights being set to Allow for a user.

The following WMI filter permissions are supported.

#### permWMIFilterEdit

The trustee can edit the WMI filter.

#### permWMIFilterFullControl

The trustee has full control over the WMI filter.

The following scope of management (SOM) permissions are supported.

#### permSOMLink

The trustee can link GPOs to the SOM. Applies to sites, domains and OUs.

#### permSOMLogging

The trustee can generate RSoP logging data for the SOM. Applies to domains and OUs.

#### permSOMPlanning

The trustee can generate RSoP planning data for the SOM. Applies to domains and OUs.

#### permSOMWMICreate

The trustee can create WMI filters in the domain. Applies to domains only.

#### permSOMWMIFullControl

The trustee has full control over all the WMI filters in the domain. Applies to domains only.

#### permSOMGPOCreate

The trustee can create GPOs in the domain. Applies to domains only.

### `bInheritable` [in]

|  |  |
| --- | --- |
| **C++** | **VARIANT_BOOL**. If **VARIANT_TRUE**, children inherit the permission. Note that this parameter is significant only when you add permissions to security information using the [IGPMSecurityInfo::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmsecurityinfo-add) method. This parameter is ignored for searches. |
| **JScript** | If true, children inherit the permission. Note that this parameter is significant only when you add permissions to security information using the [GPMSecurityInfo.Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmsecurityinfo-add) method. This parameter is ignored for searches. |

### `ppPerm` [out]

Address of a pointer to the
[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMPermission** object.

### VB

Returns a reference to a **GPMPermission** object.

## Remarks

For more information about access control lists (ACLs), access rights, and the security model for controlling access to Windows objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control). For more information about security groups, see
How [Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)