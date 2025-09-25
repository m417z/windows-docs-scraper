# IGPMSOM::GetGPOLinks

## Description

Returns a [GPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object that contains the GPO links for the scope of management (SOM). The collection is sorted in the SOM link order and contains both enabled and disabled links. See [IGPMGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolink) for the definition of SOM link order.

## Parameters

### `ppGPOLinks` [out]

Address of a pointer to an
[IGPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object.

### VB

Returns a reference to a [GPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object.

## See also

[IGPMGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolink)

[IGPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)