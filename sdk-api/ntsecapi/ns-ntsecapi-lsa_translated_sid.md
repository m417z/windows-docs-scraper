# LSA_TRANSLATED_SID structure

## Description

The **LSA_TRANSLATED_SID** structure is used with the
[LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames) function to return information about the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) that identifies an account.

## Members

### `Use`

A value from the
[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration type that identifies the type of SID.

If **Use** has one of the following values, one or both of the **RelativeId** or **DomainIndex** members of **LSA_TRANSLATED_SID** is not valid. These members are valid if **Use** has any other value.

| Value | Meaning |
| --- | --- |
| **SidTypeDomain** | The **DomainIndex** member is valid, but the **RelativeId** member is not valid and must be ignored. |
| **SidTypeInvalid** | Both **DomainIndex** and **RelativeId** are not valid and must be ignored. |
| **SidTypeUnknown** | Both **DomainIndex** and **RelativeId** members are not valid and must be ignored. |

### `RelativeId`

Specifies the relative identifier (RID) of the account's SID. The RID identifies the account relative to the domain referenced by the **DomainIndex** member. The account's complete SID consists of the domain SID followed by the RID.

### `DomainIndex`

Specifies the zero-based index of an entry in the
[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) structure returned by the [LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames) function. This entry contains the name and SID of the domain in which the account was found.

If there is no corresponding domain for an account, this member contains a negative value.

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames)

[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use)