# LSA_TRUST_INFORMATION structure

## Description

The **LSA_TRUST_INFORMATION** structure identifies a domain.

## Members

### `Name`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the domain.

### `Sid`

Pointer to the SID of the domain.

## Remarks

[TRUSTED_DOMAIN_INFORMATION_BASIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms722475(v=vs.85)) is an alias for this structure.

The [TRUSTED_DOMAIN_INFORMATION_BASIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms722475(v=vs.85)) structure identifies a domain. This structure is used by the
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) function when its *InformationClass* parameter is set to **TrustedDomainInformationBasic**.

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)