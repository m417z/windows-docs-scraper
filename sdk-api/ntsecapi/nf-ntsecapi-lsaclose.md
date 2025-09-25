# LsaClose function

## Description

The **LsaClose** function closes a handle to a Policy or [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `ObjectHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object returned by the
[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy) function or to a [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object returned by the
[LsaOpenTrustedDomainByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopentrusteddomainbyname) function. Following the completion of this call, the handle is no longer valid.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy)