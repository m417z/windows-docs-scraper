# LsaEnumerateTrustedDomainsEx function

## Description

The **LsaEnumerateTrustedDomainsEx** function returns information about the domains trusted by the local system.**LsaEnumerateTrustedDomainsEx** returns information only on direct trusts.
[DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) is recommended for more complete trust enumeration purposes.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. This call requires POLICY_VIEW_LOCAL_INFORMATION access to the **Policy** object. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `EnumerationContext` [in]

A pointer to an
[LSA_ENUMERATION_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/lsa-enumeration-handle) that you can use to make multiple calls to **LsaEnumerateTrustedDomainsEx** to retrieve all of the trusted domain information. For more information, see Remarks.

### `Buffer` [out]

Pointer to a buffer that receives a list of
[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structures that contain information about the enumerated trusted domains.

Your application should free this buffer when it is no longer needed by calling
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

### `PreferedMaximumLength` [in]

Preferred maximum length, in bytes, of returned data. This is not a hard upper limit, but serves as a guide. Due to data conversion between systems with different natural data sizes, the actual amount of data returned may be greater than this value.

### `CountReturned` [out]

Pointer to a **LONG** that receives the number of trusted domain objects returned.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | Caller does not have the appropriate access to complete the operation. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries. This warning is returned if no objects have been enumerated because the *EnumerationContext* value is too high. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

Retrieving all trust information may require more than a single **LsaEnumerateTrustedDomainsEx** call.

**To use the *EnumerationContext* parameter to make multiple calls**

1. Set the variable pointed to by *EnumerationContext* to zero.
2. If **LsaEnumerateTrustedDomainsEx** returns STATUS_SUCCESS or STATUS_MORE_ENTRIES, call the function again, passing in the *EnumerationContext* value returned by the previous call.
3. The enumeration is complete when the function returns STATUS_NO_MORE_ENTRIES.

## See also

[LSA_ENUMERATION_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/lsa-enumeration-handle)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)