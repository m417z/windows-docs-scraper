# LsaOpenTrustedDomainByName function

## Description

The **LsaOpenTrustedDomainByName** function opens the LSA policy handle of a remote trusted domain. You can pass this handle into LSA function calls in order to set or query the LSA policy of the remote machine.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. This is the policy handle of the local machine. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainName` [in]

Name of the trusted domain. This name can be either the flat name, or the Domain Name System (DNS) domain name.

### `DesiredAccess` [in]

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that specifies the access permissions requested on the remote trusted domain object.

### `TrustedDomainHandle` [out]

Pointer that receives the address of the LSA policy handle of the remote trusted domain. You can pass this handle into LSA function calls in order to query and manage the LSA policy of the remote machine.

When your application no longer needs this handle, it should call
[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose) to delete the handle.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | Caller does not have the appropriate access to complete the operation. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | There is no Trusted Domain object in the target system's LSA Database having the specified name. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose)