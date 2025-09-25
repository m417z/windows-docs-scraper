# LSA_TRANSLATED_NAME structure

## Description

The **LSA_TRANSLATED_NAME** structure is used with the
[LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids) function to return information about the account identified by a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid).

## Members

### `Use`

A value from the
[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration that identifies the type of SID.

If **Use** has one of the following values, one or both of the **Name** or **DomainIndex** members of **LSA_TRANSLATED_NAME** is not valid. These members are valid if **Use** has any other value.

| Value | Meaning |
| --- | --- |
| **SidTypeDomain** | The **DomainIndex** member is valid, but the **Name** member is not valid and must be ignored. |
| **SidTypeInvalid** | Both **DomainIndex** and **Name** are not valid and must be ignored. |
| **SidTypeUnknown** | Both **DomainIndex** and **Name** are not valid and must be ignored. |
| **SidTypeWellKnownGroup** | The **Name** member is valid, but the **DomainIndex** member is not valid and must be ignored. |

### `Name`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the isolated name of the translated SID. An isolated name is a user, group, or local group account name without the domain name (for example, user_name, rather than Acctg\user_name).

### `DomainIndex`

Specifies the zero-based index of an entry in the
[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) structure returned by the
[LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids) function. The entry contains the name and SID of the domain in which the account was found.

If there is no corresponding domain for an account, this member contains a negative value.

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids)

[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use)