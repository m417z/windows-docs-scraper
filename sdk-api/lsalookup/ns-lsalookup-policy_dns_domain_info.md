# POLICY_DNS_DOMAIN_INFO structure

## Description

The **POLICY_DNS_DOMAIN_INFO** structure is used to set and query Domain Name System (DNS) information about the primary domain associated with a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) and
[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) functions use this structure when their *InformationClass* parameters are set to **PolicyDnsDomainInformation**.

## Members

### `Name`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that specifies the name of the primary domain. This is the same as the primary domain name in the
[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info) structure.

### `DnsDomainName`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that specifies the DNS name of the primary domain.

### `DnsForestName`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that specifies the DNS forest name of the primary domain. This is the DNS name of the domain at the root of the enterprise.

### `DomainGuid`

A
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that contains the GUID of the primary domain.

### `Sid`

Pointer to the SID of the primary domain. This is the same as the primary domain SID in the [POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info) structure.

## Remarks

The **POLICY_DNS_DOMAIN_INFO** structure is an extended version of the
[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info) structure. Setting **POLICY_DNS_DOMAIN_INFO** information will overwrite the corresponding values in the **POLICY_PRIMARY_DOMAIN_INFO** (name and SID), and vice versa.

If the computer associated with the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object is not a member of a domain, all structure members except **Name** are **NULL** or zero.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)

[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info)