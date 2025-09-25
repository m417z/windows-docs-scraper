## Description

Executes a search for
[GPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom) objects (domains and organizational units) in the domain and then returns a
[GPMSOMCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsomcollection) object.

## Parameters

### `pIGPMSearchCriteria` [in]

[GPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) object to apply to the search.

### `ppIGPMSOMCollection` [out]

Address of a pointer to the
[IGPMSOMCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsomcollection) interface that represents the scopes of management (SOMs) found by the search.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMSOMCollection** object.

### VB

Returns a reference to a **GPMSOMCollection** object.

## Remarks

This method does not allow you to search for site SOMs. Call the
[IGPMSitesContainer::SearchSites](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmsitescontainer-searchsites) method to perform this type of search.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)

[IGPMSOMCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsomcollection)

[IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria)