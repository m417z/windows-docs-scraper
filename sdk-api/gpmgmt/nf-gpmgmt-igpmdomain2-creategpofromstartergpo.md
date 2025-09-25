## Description

Creates and retrieves a
[GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object from a [GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object. This method creates a new [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object. Then, this method copies the contents of the [GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object into the **GPMGPO** object. Finally, this method updates the appropriate attributes of the **GPMGPO** object to reflect the configured data.

## Parameters

### `pGPOTemplate` [in]

A pointer to a [GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object from which the new Group Policy object (GPO) will be created.

### `ppnewGPO` [out]

Address of a pointer to an [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object that represents the new GPO.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object.

### VB

Returns a reference to a [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object.

## See also

[IGPMDomain2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain2)