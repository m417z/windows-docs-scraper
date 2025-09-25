# LSA_REFERENCED_DOMAIN_LIST structure

## Description

The **LSA_REFERENCED_DOMAIN_LIST** structure contains information about the domains referenced in a lookup operation.

## Members

### `Entries`

Specifies the number of entries in the **Domains** array.

### `Domains`

Pointer to an array of
[LSA_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_trust_information) structures that identify the referenced domains.

## See also

[LSA_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_trust_information)

[LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames)

[LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids)