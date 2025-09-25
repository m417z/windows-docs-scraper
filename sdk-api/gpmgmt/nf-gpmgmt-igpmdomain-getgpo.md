# IGPMDomain::GetGPO

## Description

Retrieves a
[GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object with a specified Group Policy object (GPO) ID. The group policy object ID is represented by a GUID.

## Parameters

### `bstrGuid` [in]

Required. GUID representing the ID of the group policy object to access. Use null-terminated string.

### `ppGPO` [out]

Address of a pointer to the
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface for the group policy object ID and domain specified.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object.

### VB

Returns a reference to a [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object.

## See also

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)