## Description

Executes a search for
[GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) objects in the domain and then returns a
[GPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection) object.

## Parameters

### `pIGPMSearchCriteria` [in]

This parameter should be **NULL**, or it should point to an empty [IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) interface, because no search criteria are allowed for Windows Management Instrumentation (WMI) filters.

### `ppIGPMWMIFilterCollection` [out]

Address of a pointer to the
[IGPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpocollection) interface that represents the WMI filters found by the search.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection) object.

### VB

Returns a reference to a [GPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection) object.

## Remarks

An empty [GPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) object is one that has had no criteria added to it. Passing in an empty **GPMSearchCriteria** object will return all WMI filters.

## See also

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)

[IGPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection)