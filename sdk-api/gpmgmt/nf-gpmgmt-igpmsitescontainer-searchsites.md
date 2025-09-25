## Description

Retrieves a collection of scope of management (SOM) objects based on the specified search criteria. This method returns only site objects.

## Parameters

### `pIGPMSearchCriteria` [in]

Pointer to criteria to supply to the search. Valid criteria for the search include the following.

#### somLinks

Pointer to an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) or an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface to query the
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface. For script programmers, this is a reference to a **GPMGPO** object. Valid criteria includes the opContains search operator.

### `ppIGPMSOMCollection` [out]

Address of a pointer to the
[IGPMSOMCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsomcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMSOMCollection** object.

### VB

Returns a reference to a **GPMSOMCollection** object.

## See also

[IGPMSOMCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsomcollection)

[IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria)

[IGPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer)