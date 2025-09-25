# LsaLookupNames function

## Description

The **LsaLookupNames** function retrieves the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) that correspond to an array of user, group, or local group names.

The **LsaLookupNames** function is superseded by the [LsaLookupNames2](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames2) function. Applications should use the **LsaLookupNames2** function to ensure future compatibility.

The **LsaLookupNames** function can also retrieve computer accounts.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_LOOKUP_NAMES access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `Count` [in]

Specifies the number of names in the *Names* array. This is also the number of entries returned in the *Sids* array. This value must be less than or equal to 1000.

### `Names` [in]

Pointer to an array of
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structures that contain the names to look up. The strings in these structures can be the names of user, group, or local group accounts, or the names of domains. Domain names can be DNS domain names or NetBIOS domain names.

For more information about the format of the name strings, see Remarks.

### `ReferencedDomains` [out]

Receives a pointer to an
[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) structure. The **Domains** member of this structure is an array that contains an entry for each domain in which a name was found. The **DomainIndex** member of each entry in the *Sids* array is the index of the **Domains** array entry for the domain in which the name was found.

When you have finished using the returned pointer, free the memory by calling the
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function. This memory must be freed even when the function fails with the either of the error codes **STATUS_NONE_MAPPED** or **STATUS_SOME_NOT_MAPPED**

### `Sids` [out]

Receives a pointer to an array of
[LSA_TRANSLATED_SID](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_translated_sid) structures. Each entry in the *Sids* array contains the SID information for the corresponding entry in the *Names* array.

When you have finished using the returned pointer, free the memory by calling the
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function. This memory must be freed even when the function fails with the either of the error codes **STATUS_NONE_MAPPED** or **STATUS_SOME_NOT_MAPPED**

## Return value

If the function succeeds, the function returns one of the following **NTSTATUS** values.

| Value | Description |
| --- | --- |
| **STATUS_SOME_NOT_MAPPED** | Some of the names could not be translated. This is an informational-level return value. |
| **STATUS_SUCCESS** | All of the names were found and successfully translated. |

If the function fails, the return value is the following **NTSTATUS** value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_NONE_MAPPED** | None of the names were translated. |
| **STATUS_TOO_MANY_NAMES** | The Names array parameter was too large. |

Use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

> [!WARNING]
>Use fully qualified account names (for example, domain_name\user_name) instead of isolated names (for example, user_name). Fully qualified names are unambiguous and provide better performance when the lookup is performed. This function also supports fully qualified DNS names (for example, example.example.com\user_name) and [user principal names](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) (for example, someone@example.com).

> [!WARNING]
>For more information about the limitations of isolated names, please refer to the [LsaLookupNames2](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames2) documentation.

The **LsaLookupNames** function uses the following algorithm to translate account names.

**To translate names**

1. If the name is a well-known name, such as Local or Interactive, the function returns the corresponding well-known [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).
2. If the name is the name of the built-in domain, the function returns the SID of that domain.
3. If the name is the name of the account domain, the function returns the SID of that domain.
4. If the name is the name of the primary domain, the function returns the SID of that domain.
5. If the name is one of the names of the trusted domain, the function returns the SID of that domain.
6. If the name is a user, group, or local group account in the built-in domain, the function returns the SID of that account.
7. If the name is a user, group, or local group account in the account domain on the local system, the function returns the SID of that account.
8. If the name is found in the cache, the function returns the SID of that account.- If the name is a user, group, or a local group in the primary domain, the function returns the SID of that account.
   - After looking in the primary domain, the primary domain looks in each of its trusted domains.
   - Otherwise, the name is not translated.

In addition to looking up local accounts, local domain accounts, and explicitly trusted domain accounts, **LsaLookupNames** can look up the name of any account in any domain in the Windows forest.

#### Examples

For an example that calls this function, see
[Translating Between Names and SIDs](https://learn.microsoft.com/windows/desktop/SecMgmt/translating-between-names-and-sids).

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LSA_TRANSLATED_SID](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_translated_sid)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids)