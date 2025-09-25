# IGPMSOM::GetInheritedGPOLinks

## Description

Returns a [GPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object that contains the GPO links that are applied to the scope of management (SOM), including links inherited from parent containers (OUs and domains). The collection does not include GPO links from site SOMs or disabled links. The collection is sorted in order of precedence, with the first (earliest) link having the highest priority and last (latest) link having the lowest priority. Note that the GPOs are applied in reverse order of their precedence. The last GPO in the list is applied first and the first GPO in the list is applied last.

## Parameters

### `ppGPOLinks` [out]

Address of a pointer to an
[IGPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object.

### VB

Returns a reference to a [GPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection) object.

## See also

[IGPMGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolink)

[IGPMGPOLinksCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolinkscollection)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)