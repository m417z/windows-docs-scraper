# TRUSTED_DOMAIN_INFORMATION_EX structure

## Description

The **TRUSTED_DOMAIN_INFORMATION_EX** structure is used to retrieve extended information about a trusted domain. The
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) function uses this structure when its *InformationClass* parameter is set to TrustedDomainInformationEx.

## Members

### `Name`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the trusted domain. This is the DNS domain name. For non-Microsoft trusted domains, this is the identifying name of the domain.

### `FlatName`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the flat name of the trusted domain. For non-Microsoft trusted domains, this is the identifying name of the domain or it is **NULL**.

### `Sid`

Pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the trusted domain. For non-Microsoft trusted domains, this member can be **NULL**.

### `TrustDirection`

A value that indicates the direction of the trust. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUST_DIRECTION_DISABLED** | The trust relationship exists, but it has been disabled. |
| **TRUST_DIRECTION_INBOUND** | The trusted domain trusts the primary domain to perform operations such as name lookups and authentication. |
| **TRUST_DIRECTION_OUTBOUND** | The primary domain trusts the trusted domain to perform operations such as name lookups and authentication. |
| **TRUST_DIRECTION_BIDIRECTIONAL** | Both domains trust each other. |

### `TrustType`

A value that indicates the type of the trust relationship. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUST_TYPE_DOWNLEVEL** | The domain controller of the trusted domain is a computer running an operating system earlier than Windows 2000. |
| **TRUST_TYPE_UPLEVEL** | The domain controller of the Microsoft trusted domain is a computer running Windows 2000 or later. |
| **TRUST_TYPE_MIT** | The trusted domain is an MIT Kerberos realm. |
| **TRUST_TYPE_DCE** | The trusted domain is a DCE realm. |
| **0x5 - 0x000FFFFF** | Reserved for future use. |
| **0x00100000 to 0xFFF00000** | Provider-specific trust levels. |

### `TrustAttributes`

A value that indicates the attributes of a trust relationship. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUST_ATTRIBUTE_NON_TRANSITIVE** | Disallow transitivity. |
| **TRUST_ATTRIBUTE_UPLEVEL_ONLY** | The trust link is not valid for client operating systems earlier than Windows 2000. |
| **TRUST_ATTRIBUTE_FILTER_SIDS** | Quarantine domains. |
| **TRUST_ATTRIBUTE_FOREST_TRANSITIVE** | The trust link may contain forest trust information. |
| **TRUST_ATTRIBUTE_CROSS_ORGANIZATION** | This trust is to a domain/forest that is not part of this enterprise. |
| **TRUST_ATTRIBUTE_TREAT_AS_EXTERNAL** | Trust is treated as external for trust boundary purposes. |
| **TRUST_ATTRIBUTE_WITHIN_FOREST** | Trust is internal to this forest. |

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaCreateTrustedDomainEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacreatetrusteddomainex)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaQueryTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfobyname)

[LsaSetTrustedDomainInfoByName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininfobyname)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)