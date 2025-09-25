# LsaQueryTrustedDomainInfo function

## Description

The **LsaQueryTrustedDomainInfo** function retrieves information about a trusted domain.

## Parameters

### `PolicyHandle` [in]

A handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object of a domain controller that has a trust relationship with the domain identified by the *TrustedDomainSid* parameter. The handle must have the POLICY_VIEW_LOCAL_INFORMATION access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainSid` [in]

Pointer to the SID of the trusted domain to query.

### `InformationClass` [in]

Specifies one of the following values from the
[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class) enumeration type. The value indicates the type of information being requested.

| Value | Meaning |
| --- | --- |
| **TrustedDomainNameInformation** | Retrieves the name of the trusted domain. The *Buffer* parameter receives a pointer to a [TRUSTED_DOMAIN_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_name_info) structure. |
| **TrustedPosixOffsetInformation** | Retrieves the value used to generate Posix user and group identifiers for the trusted domain. The *Buffer* parameter receives a pointer to a [TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info) structure. |
| **TrustedPasswordInformation** | Retrieves the password for the trusted domain. The *Buffer* parameter receives a pointer to a [TRUSTED_PASSWORD_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_password_info) structure. The handle passed in the *PolicyHandle* parameter must have the POLICY_GET_PRIVATE_INFORMATION access right. |
| **TrustedDomainInformationEx** | Retrieves extended information for the trusted domain. The *Buffer* parameter receives a pointer to a [TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure. |
| **TrustedDomainInformationBasic** | This value is not supported. |
| **TrustedDomainFullInformation** | Retrieves complete information for the trusted domain. This information includes the Posix offset information, authentication information, and the extended information returned for the TrustedDomainInformationEx value. The *Buffer* parameter receives a pointer to a [TRUSTED_DOMAIN_FULL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_full_information) structure. |

### `Buffer` [out]

A pointer to a buffer that receives a pointer to a structure that contains the requested information. The type of structure depends on the value of the *InformationClass* parameter.

When you have finished using the information, free the returned pointer by passing it to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** value that indicates the error. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** value to a Windows error code.

## See also

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)

[POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info)

[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info)

[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info)

[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info)

[POLICY_MODIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_modification_info)

[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)