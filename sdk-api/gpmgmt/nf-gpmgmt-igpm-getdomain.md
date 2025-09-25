# IGPM::GetDomain

## Description

Creates and returns a
[GPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain) object that corresponds to the specified domain.

The object allows you to do the following:

* Create, query, and restore Group Policy objects (GPOs)
* Search scope of management (SOM) objects
* Search and retrieve Windows Management Instrumentation (WMI) filters

## Parameters

### `bstrDomain` [in]

Name of the domain specified as a string. This must be a full Domain Name System (DNS) name, such as `contoso.com`.

### `bstrDomainController` [in]

If specified, the name of the domain controller to use with the domain. The name can be a DNS name or a NetBIOS name. Otherwise, the method uses the primary domain controller (PDC). For more information, see the *lDCFlags* parameter.

**Scripting:** This parameter must pass an empty string ("") when a domain controller is not specified.

### `lDCFlags` [in]

Flags to use to locate the domain controller for the domain. You can specify **GPM_USE_ANYDC**, **GPM_USE_PDC**, or **GPM_DONOTUSE_W2KDC**.

If this parameter is set to zero, and a *bstrDomainController* is specified, the method uses the specified *bstrDomainController*. Otherwise, the method uses the PDC.

### `pIGPMDomain` [out]

Address of a pointer to the
[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMDomain** object.

### VB

Returns a reference to a **GPMDomain** object.

## Remarks

>**Important:** When calling this function, underlying LDAP traffic is encrypted using Kerberos, not SSL.

This method does not allow you to search site SOMs. Call the
[IGPM::GetSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpm-getsitescontainer) method to perform this type of query.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)