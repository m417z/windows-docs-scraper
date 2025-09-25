## Description

Executes a search for
[GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) objects in the domain and returns a
[GPMStarterGPOCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpocollection) object.

## Parameters

### `pIGPMSearchCriteria` [in]

Pointer to the criteria to apply to the search.

### `ppIGPMTemplateCollection` [out]

Address of a pointer to the
[IGPMStarterGPOCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpocollection) interface that represents the GPOs found by the search.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMStarterGPOCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpocollection) object.

### VB

Returns a reference to a [GPMStarterGPOCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpocollection) object.

## See also

[IGPMDomain2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain2)