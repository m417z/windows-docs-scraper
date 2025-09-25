# TRUSTED_DOMAIN_FULL_INFORMATION structure

## Description

The **TRUSTED_DOMAIN_FULL_INFORMATION** structure is used to retrieve complete information about a trusted domain. The
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) function uses this structure when its *InformationClass* parameter is set to **TrustedDomainFullInformation**.

## Members

### `Information`

A
[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure containing extended information for a trusted domain.

### `PosixOffset`

A
[TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info) structure containing the value used to generate Posix user and group identifiers for a trusted domain.

### `AuthInformation`

A
[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information) structure containing authentication information for a trusted domain.

## See also

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)

[TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info)