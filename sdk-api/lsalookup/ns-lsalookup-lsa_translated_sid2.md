# LSA_TRANSLATED_SID2 structure

## Description

The **LSA_TRANSLATED_SID2** structure contains
[SIDs](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) that are retrieved based on account names. This structure is used by the
[LsaLookupNames2](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames2) function.

## Members

### `Use`

An
[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration value that identifies the use of the SID. If this value is SidTypeUnknown or SidTypeInvalid, the rest of the information in the structure is not valid and should be ignored.

### `Sid`

The complete SID of the account.

### `DomainIndex`

The index of an entry in a related
[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) data structure which describes the domain that owns the account. If there is no corresponding reference domain for an entry, then **DomainIndex** will contain a negative value.

### `Flags`

Not used.