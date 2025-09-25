# POLICY_PRIMARY_DOMAIN_INFO structure

## Description

The **PolicyPrimaryDomainInformation** value and **POLICY_PRIMARY_DOMAIN_INFO** structure are obsolete. Use the **PolicyDnsDomainInformation** and
[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info) structure instead.

## Members

### `Name`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that specifies the name of the primary domain.

### `Sid`

Pointer to the SID of the primary domain.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)