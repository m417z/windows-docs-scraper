# IGPMGPO::GetWMIFilter

## Description

Retrieves the
[GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object linked to the Group Policy object (GPO).

## Parameters

### `ppIGPMWMIFilter` [out]

Address of a pointer to the
[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns S_FALSE if no WMI filter is linked to the GPO. Returns a failure code if an error occurs.

### JScript

If the GPO is linked to a WMI filter, the method returns a reference to a [GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object. If the GPO is not linked to a WMI filter, the method returns a null reference.

### VB

If the GPO is linked to a WMI filter, the method returns a reference to a [GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object. If the GPO is not linked to a WMI filter, the method returns a null reference.

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)