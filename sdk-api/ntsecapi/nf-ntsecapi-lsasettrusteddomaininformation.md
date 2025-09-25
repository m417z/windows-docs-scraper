# LsaSetTrustedDomainInformation function

## Description

The **LsaSetTrustedDomainInformation** function modifies a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object's information about a trusted domain.

## Parameters

### `PolicyHandle` [in]

A handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object of a domain controller. The required user rights for this handle depend on the value of the *InformationClass* parameter. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainSid` [in]

Pointer to the SID of the trusted domain whose information is modified. If the *InformationClass* parameter is set to TrustedDomainNameInformation, this parameter must point to the SID of the domain to add to the list of trusted domains.

### `InformationClass` [in]

Specifies one of the following values from the
[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class) enumeration type. The value indicates the type of information being set.

| Value | Meaning |
| --- | --- |
| **TrustedDomainNameInformation** | If the specified domain is not in the list of trusted domains, the **LsaSetTrustedDomainInformation** function adds it. The *TrustedDomainSid* parameter must be the SID of the domain to add. The *Buffer* parameter must be a pointer to a [TRUSTED_DOMAIN_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_name_info) structure containing the name of the domain to add. <br><br>If the specified domain is already in the list of trusted domains, the function fails. |
| **TrustedPosixOffsetInformation** | Sets the value used to generate Posix user and group identifiers. The *Buffer* parameter must be a pointer to a [TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info) structure. |
| **TrustedPasswordInformation** | Sets the password for the trusted domain. The *Buffer* parameter must be a pointer to a [TRUSTED_PASSWORD_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_password_info) structure containing the old and new passwords for the specified domain. The handle passed in the *PolicyHandle* parameter must have the POLICY_CREATE_SECRET access right. The old password string can be **NULL**. |

### `Buffer` [in]

Pointer to a structure containing the information to set. The type of structure depends on the value of the *InformationClass* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LsaDeleteTrustedDomain](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsadeletetrusteddomain)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[TRUSTED_DOMAIN_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_name_info)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)

[TRUSTED_PASSWORD_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_password_info)

[TRUSTED_POSIX_OFFSET_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_posix_offset_info)