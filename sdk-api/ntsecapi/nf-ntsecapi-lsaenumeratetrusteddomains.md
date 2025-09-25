# LsaEnumerateTrustedDomains function

## Description

The **LsaEnumerateTrustedDomains** function retrieves the names and SIDs of domains trusted to authenticate logon [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). **LsaEnumerateTrustedDomains** is intended for use on systems running Windows NT 4.0 or earlier versions of Windows NT. Use
[DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) for any other trust enumeration purpose. Specifically, **LsaEnumerateTrustedDomains** can only be used if one or more of the following is true:

* The calling system is running Windows NT 4.0 or an earlier version of Windows NT.
* The target system (specified using the *PolicyHandle* parameter), is a domain controller running Windows NT 4.0 or an earlier version.
* The calling system is running Windows NT 4.0 or earlier version and is not a domain controller, and the target system is a domain controller in the calling system's domain. The target system can be running any version of Windows NT, including Windows 2000 and Windows XP.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_VIEW_LOCAL_INFORMATION access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `EnumerationContext` [in]

Pointer to an enumeration handle that enables you to make multiple calls to enumerate all the trusted domains. On the first call to **LsaEnumerateTrustedDomains**, *EnumerationContext* must point to a variable that has been initialized to zero. On subsequent calls to **LsaEnumerateTrustedDomains**, *EnumerationContext* must point to the enumeration handle returned by the previous call.

### `Buffer` [out]

Receives a pointer to an array of
[LSA_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_trust_information) structures that contain the names and SIDs of one or more trusted domains.

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

### `PreferedMaximumLength` [in]

Specifies the preferred maximum size, in bytes, of the returned buffer. This information is approximate; the actual number of bytes returned may be greater than this value.

### `CountReturned` [out]

Pointer to a variable that receives the number of elements returned in the *Buffer* parameter.

## Return value

If the function is successful, the return value is one of the following NTSTATUS values.

| Value | Description |
| --- | --- |
| **STATUS_SUCCESS** | The enumeration has been successfully completed. |
| **STATUS_MORE_ENTRIES** | The call was successful, but there are more trusted domains to be enumerated. Call [LsaEnumerateTrustedDomains](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomains) again, passing the value returned in the *EnumerationContext* parameter. |
| **STATUS_NO_MORE_ENTRIES** | There are no more trusted domains to enumerate. |

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

For domains with domain controllers running only Windows NT 4.0 or earlier versions of Windows NT, **LsaEnumerateTrustedDomains** returns a list of all trusted domains. In releases of Windows NT up to and including release 4.0, all trusted domains are directly trusted.

In Windows XP and Windows 2000 mixed-mode domains, domain controllers may be running Windows XP, Windows 2000, or Windows NT. Therefore, in mixed-mode domains, some trusted domains are directly trusted and others are indirectly trusted. When enumerating the trusted domains of a system in a mixed-mode domain, **LsaEnumerateTrustedDomains** returns only directly trusted domains.

In contrast, Windows XP and Windows 2000 native-mode domains contain only Windows 2000 domain controllers, even though there may be members in the domain running Windows NT 4.0 or earlier versions. When enumerating the trusted domains of a system in a native-mode Windows XP and Windows 2000 domain, **LsaEnumerateTrustedDomains** returns both directly trusted and indirectly trusted domains.

Retrieving all trust information may require more than a single **LsaEnumerateTrustedDomains** call. You can use the *EnumerationContext* parameter to make multiple calls, as follows: On the first call, set the variable pointed to by *EnumerationContext* to zero. If **LsaEnumerateTrustedDomains** returns STATUS_SUCCESS or STATUS_MORE_ENTRIES, call the function again, passing in the *EnumerationContext* value returned by the previous call. The enumeration is complete when the function returns STATUS_NO_MORE_ENTRIES.

## See also

**LSA_TRUST_INFORMATION**

[LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy)