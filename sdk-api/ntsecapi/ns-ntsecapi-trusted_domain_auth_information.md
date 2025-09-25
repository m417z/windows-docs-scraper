# TRUSTED_DOMAIN_AUTH_INFORMATION structure

## Description

The **TRUSTED_DOMAIN_AUTH_INFORMATION** structure is used to retrieve authentication information for a trusted domain. The
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) function uses this structure when its *InformationClass* parameter is set to **TrustedDomainAuthInformation**.

## Members

### `IncomingAuthInfos`

Specifies the number of entries in the **IncomingAuthenticationInformation** and **IncomingPreviousAuthenticationInformation** arrays.

### `IncomingAuthenticationInformation`

Pointer to an array of
[LSA_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_auth_information) structures containing the authentication information for the incoming side of a trust relationship.

### `IncomingPreviousAuthenticationInformation`

Pointer to an array of [LSA_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_auth_information) structures containing the previous authentication information (or old password) for the incoming side of a trust relationship. There must be one of these for every entry in the **IncomingAuthenticationInformation** array.

### `OutgoingAuthInfos`

Specifies the number of entries in the **OutgoingAuthenticationInformation** and **OutgoingPreviousAuthenticationInformation** arrays.

### `OutgoingAuthenticationInformation`

Pointer to an array of [LSA_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_auth_information) structures containing the authentication information for the outgoing side of a trust relationship.

### `OutgoingPreviousAuthenticationInformation`

Pointer to an array of [LSA_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_auth_information) structures containing the previous authentication information (or old password) for the outgoing side of a trust relationship. There must be one of these for every entry in the **OutgoingAuthenticationInformation** array.

## See also

[LSA_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_auth_information)

[LsaCreateTrustedDomainEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacreatetrusteddomainex)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaQueryTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfobyname)

[LsaSetTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininfobyname)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)