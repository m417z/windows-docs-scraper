## Description

Sets the list of permissions for the current WMI filter to that specified by the object.

## Parameters

### `pSecurityInfo` [in]

Pointer to an
[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo) interface. This parameter is required.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

You should understand these considerations before changing permissions on WMI filters.

* Read permission is required for all users to whom a WMI filter applies. Authenticated users always have read access to all WMI filters. Typically, all users to whom the GPO with the WMI filter link applies also have read access.
* Users with permission to edit WMI filters can affect policy processing for all users to whom the WMI filter applies.

## See also

[IGPMSecurityInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsecurityinfo)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)

[IGPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection)