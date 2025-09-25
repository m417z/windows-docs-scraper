# LsaQueryTrustedDomainInfoByName function

## Description

The **LsaQueryTrustedDomainInfoByName** function returns information about a trusted domain.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. This handle must have the POLICY_VIEW_LOCAL_INFORMATION access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainName` [in]

String that contains the name of the trusted domain. This can either be the domain name or the flat name.

### `InformationClass` [in]

Specifies the type of information to retrieve. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TrustedDomainNameInformation** | Name of the trusted domain. |
| **TrustedPosixInformation** | Posix offset of the trusted domain. |
| **TrustedPasswordInformation** | Returns the password on the outbound side of the trust. |
| **TrustedDomainInformationBasic** | This value is not supported. |
| **TrustedDomainInformationEx** | Extended trust information, including the basic information and DNS domain name, and attributes about the trust. |
| **TrustedDomainFullInformation** | Full information, including the Posix offset and the authentication information. |

### `Buffer` [out]

Receives a pointer to the returned buffer that contains the requested information. The format and content of this buffer depend on the information class. For example, if *InformationClass* is set to TrustedDomainInformationEx, *Buffer* receives a pointer to a
[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure. For more information, see
[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class).

When you have finished using the buffer, free it by calling the [LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** value, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | Caller does not have the appropriate access to complete the operation. For a list of the required access types, see the description of the *InformationClass* parameter. |
| **STATUS_INSUFFICIENT_ RESOURCES** | Insufficient system resources, such as memory, to complete the call. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** value to a Windows error code.

## See also

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaSetTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininfobyname)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)