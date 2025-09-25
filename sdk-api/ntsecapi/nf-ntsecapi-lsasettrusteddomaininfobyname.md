# LsaSetTrustedDomainInfoByName function

## Description

The **LsaSetTrustedDomainInfoByName** function sets values for a
[TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the trusted domain object determines whether the caller's changes are accepted. For information about policy object handles, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainName` [in]

Name of the trusted domain to set values for. This can either be the domain name or the flat name.

### `InformationClass` [in]

Specifies the type of information to set. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **TrustedPosixInformation** | Posix offset of the trusted domain. |
| **TrustedDomainInformationEx** | Extended trust information, including the basic information and DNS domain name, and attributes about the trust. |
| **TrustedDomainAuthInformation** | Authentication information for the trust, including authentication information for both the inbound and outbound side of the trust (if it exists). |
| **TrustedDomainFullInformation** | Full information, including the Posix offset and the authentication information. |

### `Buffer` [in]

Pointer to a structure that contains the information to set. The type of structure depends on the value of the *InformationClass* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
the "LSA Policy Function Return Values" section of [Security Management Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LsaQueryTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfobyname)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)