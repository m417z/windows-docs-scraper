# IGPMStarterGPO::GetSecurityInfo

## Description

Retrieves the set of permissions for the Starter GPO, such as who is granted permission to edit it.

## Parameters

### `ppSecurityInfo` [out]

Address of a pointer to the
[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) interface.

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission).

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)