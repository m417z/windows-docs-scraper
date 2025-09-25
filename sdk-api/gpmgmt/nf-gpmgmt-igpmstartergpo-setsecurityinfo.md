# IGPMStarterGPO::SetSecurityInfo

## Description

Sets the list of permissions for the Group Policy object (GPO), such as who is granted permission to edit it. The method replaces the existing list of permissions.

## Parameters

### `pSecurityInfo` [in]

Pointer to the security information to apply to the GPO.

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission).

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)