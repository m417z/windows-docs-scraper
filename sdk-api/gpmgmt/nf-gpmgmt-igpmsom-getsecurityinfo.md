# IGPMSOM::GetSecurityInfo

## Description

Returns an object that represents the collection of
[GPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission) objects for the scope of management (SOM).

## Parameters

### `ppSecurityInfo` [out]

Address of a pointer to an
[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) object.

### VB

Returns a reference to a [GPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) object.

## See also

[GPMPermission](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmpermission)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)