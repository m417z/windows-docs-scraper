# IGPM::GetSitesContainer

## Description

Creates and returns a
[GPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer) object from which sites can be opened and queried.

## Parameters

### `bstrForest` [in]

Required. Full DNS name of the forest in which to access sites; this is the name of the forest root domain. Use null-terminated string.

### `bstrDomain` [in]

Name of the domain in which to access sites. If specified, this must be a full Domain Name Server (DNS) name, such as example.microsoft.com. If a domain is specified in the *bstrDomain* parameter, the Group Policy Management Console (GPMC) accesses sites through that domain. If no domain is specified, the GPMC accesses the sites through the forest that is specified in the *bstrForest* parameter. Use a null-terminated string.

### `bstrDomainController` [in]

If specified, the name of the domain controller to use with the domain specified in the *bstrDomain* parameter. The name can be a DNS name or a NetBIOS name. Otherwise, the method uses the primary domain controller (PDC). Use a null-terminated string.

### `lDCFlags` [in]

Flags to use to locate the domain controller for the domain. Currently, the only supported value is GPM_USE_ANYDC. If this parameter is set to zero, and *bstrDomainController* is specified, the method uses the specified domain controller. Otherwise, the method uses the PDC.

### `ppIGPMSitesContainer` [out]

Address of a pointer to the
[IGPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer) object.

### VB

Returns a reference to a [GPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer) object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer)