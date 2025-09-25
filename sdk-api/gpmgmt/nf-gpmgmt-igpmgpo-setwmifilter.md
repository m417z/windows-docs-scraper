## Description

Links the
[GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object to the current Group Policy object (GPO). This method can also be used to unlink existing WMI filters from the GPO.

## Parameters

### `pIGPMWMIFilter` [in]

Pointer to the WMI filter to associate with the current GPO. Passing **NULL** in this parameter unlinks any existing WMI filters.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)