# TRUSTED_POSIX_OFFSET_INFO structure

## Description

The **TRUSTED_POSIX_OFFSET_INFO** structure is used to query or set the value used to generate Posix user and group identifiers. The
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) and
[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation) functions use this structure when their *InformationClass* parameters are set to **TrustedPosixOffsetInformation**.

## Members

### `Offset`

An offset that the system uses to generate Posix user and group identifiers that correspond to a given SID. To generate a Posix identifier, the system adds the RID from the SID to the Posix offset of the trusted domain identified by the SID.

## See also

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)