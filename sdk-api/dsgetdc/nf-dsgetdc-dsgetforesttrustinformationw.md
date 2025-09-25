# DsGetForestTrustInformationW function

## Description

The **DsGetForestTrustInformationW** function obtains forest trust data for a specified domain.

## Parameters

### `ServerName` [in, optional]

Contains the name of the domain controller that **DsGetForestTrustInformationW** is connected to remotely.
The caller must be an authenticated user on this server.
If this parameter is **NULL**, the local server is used.

### `TrustedDomainName` [in, optional]

Contains the NETBIOS or DNS name of the trusted domain that the forest trust data
is to be retrieved for. This domain must have the
**TRUST_ATTRIBUTE_FOREST_TRANSITIVE** trust attribute. For more information, see [TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex).

If this parameter is **NULL**, the forest trust
data for the domain hosted by *ServerName* is retrieved.

### `Flags` [in]

Contains a set of flags that modify the behavior of this function. This can be zero or the following value.

#### DS_GFTI_UPDATE_TDO

If this flag is set, **DsGetForestTrustInformationW** will update
the forest trust data of the trusted domain identified by the *TrustedDomainName* parameter. In this case, the *TrustedDomainName* parameter cannot be **NULL**.
The caller must have access to modify the trust data or
**ERROR_ACCESS_DENIED** is returned.

This flag is only valid if *ServerName* specifies the primary domain controller of the domain.

### `ForestTrustInfo` [out]

Pointer to an [LSA_FOREST_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_information) structure pointer that receives the forest trust data that describes the namespaces claimed by the
domain specified by *TrustedDomainName*. The **Time** member of all returned records will be zero.

The caller must free this structure when it is no longer required by calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

## Return value

Returns **NO_ERROR** if successful or a Win32 error code otherwise. Possible error codes include the following.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)