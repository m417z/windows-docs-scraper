# IGPMDomain2::GetStarterGPO

## Description

Retrieves a
[GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object that has a specified Group Policy object ID. The GPO ID is represented by a GUID.

## Parameters

### `bstrGuid` [in]

Required. GUID that represents the ID of the GPO to access. Use a null-terminated string.

### `ppTemplate` [out]

Address of a pointer to the
[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) interface for the specified Starter GPO ID.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object.

### VB

Returns a reference to a [GPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) object.

## See also

[IGPMDomain2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain2)