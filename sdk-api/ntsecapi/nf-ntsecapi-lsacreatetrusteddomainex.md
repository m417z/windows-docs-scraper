# LsaCreateTrustedDomainEx function

## Description

The **LsaCreateTrustedDomainEx** function establishes a new trusted domain by creating a new [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. For the object to be created, the caller must have permission to create children on the **System** container. For information about policy object handles, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainInformation` [in]

Pointer to a
[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure that contains the name and SID of the new trusted domain.

### `AuthenticationInformation` [in]

Pointer to a
[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information) structure that contains authentication information for the new trusted domain.

### `DesiredAccess` [in]

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that specifies the accesses to be granted for the new trusted domain.

### `TrustedDomainHandle` [out]

Receives the LSA policy handle of the remote trusted domain. You can pass this handle into LSA function calls to manage the LSA policy of the trusted domain.

When your application no longer needs this handle, it should call
[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose) to delete the handle.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_DIRECTORY_SERVICE_REQUIRED** | The target system (specified in the *TrustedDomainInformation* parameter) for the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object is not a domain controller. |
| **STATUS_INVALID_SID** | The specified SID is not valid. |
| **STATUS_UNSUCCESSFUL** | Unable to determine whether the target system is a domain controller. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

**LsaCreateTrustedDomainEx** does not check whether the specified domain name matches the specified SID or whether the SID and name represent an actual domain.

## See also

[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose)

[LsaDeleteTrustedDomain](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsadeletetrusteddomain)

[LsaSetTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininfobyname)

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)

[TRUSTED_DOMAIN_AUTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_auth_information)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)