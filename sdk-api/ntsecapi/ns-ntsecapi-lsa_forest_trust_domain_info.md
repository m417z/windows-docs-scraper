# LSA_FOREST_TRUST_DOMAIN_INFO structure

## Description

The **LSA_FOREST_TRUST_DOMAIN_INFO** structure contains identifying information for a domain.

## Members

### `Sid`

Pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the domain.

### `DnsName`

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the DNS name of the domain.

### `NetbiosName`

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the NetBIOS name of the domain.