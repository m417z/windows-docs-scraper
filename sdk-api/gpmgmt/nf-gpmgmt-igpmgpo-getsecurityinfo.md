# IGPMGPO::GetSecurityInfo

## Description

Retrieves the set of permissions for the GPO, such as who is granted permission to edit it.

## Parameters

### `ppSecurityInfo` [out]

Address of a pointer to the
[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMSecurityInfo** object.

### VB

Returns a reference to a **GPMSecurityInfo** object.

## Remarks

For more information about policy-related permissions, see
[IGPM::CreatePermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-createpermission).

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)