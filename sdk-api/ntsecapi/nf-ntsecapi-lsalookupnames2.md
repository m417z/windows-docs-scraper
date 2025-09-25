# LsaLookupNames2 function

## Description

The **LsaLookupNames2** function retrieves the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) for specified account names. **LsaLookupNames2** can look up the SID for any account in any domain in a Windows forest.

The [LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames) function is superseded by the **LsaLookupNames2** function. Applications should use the **LsaLookupNames2** function to ensure future compatibility.

This function differs from the
[LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames) function in that **LsaLookupNames2** returns each SID as a single element, while **LsaLookupNames** divides each SID into an RID/domain pair.

## Parameters

### `PolicyHandle` [in]

A handle to a
[Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_LOOKUP_NAMES access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `Flags` [in]

Values that control the behavior of this function. The following value is currently defined.

| Value | Meaning |
| --- | --- |
| **LSA_LOOKUP_ISOLATED_AS_LOCAL**<br><br>0x80000000 | The function searches only on the local systems for names that do not specify a domain. The function does search on remote systems for names that do specify a domain. |

### `Count` [in]

Specifies the number of names in the *Names* array. This is also the number of entries returned in the *Sids* array.

### `Names` [in]

Pointer to an array of
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structures that contain the names to look up. These strings can be the names of user, group, or local group accounts, or the names of domains. Domain names can be DNS domain names or NetBIOS domain names.

For more information about the format of the name strings, see Remarks.

### `ReferencedDomains` [out]

Receives a pointer to an
[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) structure. The **Domains** member of this structure is an array that contains an entry for each domain in which a name was found. The **DomainIndex** member of each entry in the *Sids* array is the index of the **Domains** array entry for the domain in which the name was found.

When you have finished using the returned pointer, free it by calling the
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function. This memory must be freed even when the function fails with the either of the error codes **STATUS_NONE_MAPPED** or **STATUS_SOME_NOT_MAPPED**

### `Sids` [out]

Receives a pointer to an array of
[LSA_TRANSLATED_SID2](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_translated_sid2) structures. Each entry in the *Sids* array contains the SID information for the corresponding entry in the *Names* array.

When you have finished using the returned pointer, free it by calling the
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

Use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

Use fully qualified account names (for example, *DomainName*\*UserName*) instead of isolated names (for example, *UserName*). Fully qualified names are unambiguous and provide better performance when the lookup is performed. This function also supports fully qualified DNS names (for example, *Example*.*Example*.com\*UserName*) and [user principal names](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) (for example, *Someone*@*Example*.com).

Translation of isolated names introduces the possibility of name collisions because the same name may be used in multiple domains. The **LsaLookupNames2** function uses the following algorithm to translate isolated names.

**To translate isolated names**

1. If the name is a well-known name, such as Local or Interactive, the function returns the corresponding well-known [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).
2. If the name is the name of the built-in domain, the function returns the SID of that domain.
3. If the name is the name of the account domain, the function returns the SID of that domain.
4. If the name is the name of the primary domain, the function returns the SID of that domain.
5. If the name is one of the names of the trusted domain, the function returns the SID of that domain.
6. If the name is a user, group, or local group account in the built-in domain, the function returns the SID of that account.
7. If the name is a user, group, or local group account in the account domain on the local system, the function returns the SID of that account.
8. If the name is a user, group, or a local group in the primary domain, the function returns the SID of that account.
9. After looking in the primary domain, the function looks in each of the primary domain's trusted domains.
10. Otherwise, the name is not translated.

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LSA_TRANSLATED_SID2](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_translated_sid2)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)