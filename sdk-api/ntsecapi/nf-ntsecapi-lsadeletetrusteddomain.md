# LsaDeleteTrustedDomain function

## Description

The **LsaDeleteTrustedDomain** function removes a trusted domain from the list of trusted domains for a system and deletes the associated [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `TrustedDomainSid` [in]

Pointer to the SID of the trusted domain to be removed.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)