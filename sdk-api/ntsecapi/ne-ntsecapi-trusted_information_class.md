# TRUSTED_INFORMATION_CLASS enumeration

## Description

The **TRUSTED_INFORMATION_CLASS** enumeration type defines values that indicate the type of information to set or query for a trusted domain.

Each value has an associated structure that the
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) and
[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation) functions use to store the information.

## Constants

### `TrustedDomainNameInformation:1`

Query or set the name of a trusted domain. Use the
[TRUSTED_DOMAIN_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_name_info) structure.

### `TrustedControllersInformation`

This value is obsolete.

### `TrustedPosixOffsetInformation`

Query or set the value used to generate Posix user and group identifiers. Use the
[TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info) structure.

### `TrustedPasswordInformation`

This value has been superseded by the **TrustedDomainAuthInformation** value.

### `TrustedDomainInformationBasic`

This value is obsolete.

### `TrustedDomainInformationEx`

Query extended information for a trusted domain. Use the
[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure.

### `TrustedDomainAuthInformation`

Query authentication information for a trusted domain. Use the
[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information) structure.

### `TrustedDomainFullInformation`

Query complete information for a trusted domain. This information includes the Posix offset information, authentication information, and the extended information returned for the **TrustedDomainInformationEx** value. Use the
[TRUSTED_DOMAIN_FULL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_full_information) structure.

### `TrustedDomainAuthInformationInternal`

### `TrustedDomainFullInformationInternal`

### `TrustedDomainInformationEx2Internal`

### `TrustedDomainFullInformation2Internal`

### `TrustedDomainSupportedEncryptionTypes`

## See also

[LSA_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_trust_information)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)

[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information)

[TRUSTED_DOMAIN_FULL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_full_information)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)

[TRUSTED_DOMAIN_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_name_info)

[TRUSTED_PASSWORD_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_password_info)

[TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info)