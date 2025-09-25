# LsaLookupSids2 function

## Description

The **LsaLookupSids2** function looks up the names that correspond to an array of [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) and supports Internet provider identities. If **LsaLookupSids2** cannot find a name that corresponds to a SID, the function returns the SID in character form. You should use this function instead of the [LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids) function.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. This handle must have the POLICY_LOOKUP_NAMES access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `LookupOptions` [in]

Flags that modify the lookup behavior.

| Value | Meaning |
| --- | --- |
| **LSA_LOOKUP_DISALLOW_CONNECTED_ACCOUNT_INTERNET_SID** | Internet SIDs from identity providers for connected accounts are disallowed. Connected accounts are those accounts which have a corresponding shadow account in the local SAM database connected to an online identity provider. For example, MicrosoftAccount is a connected account. |
| **LSA_LOOKUP_PREFER_INTERNET_NAMES** | Returns the internet names. Otherwise the NT4 style name (domain\username) is returned. The exception is if the Microsoft Account internet SID is specified, in which case the internet name is returned unless **LSA_LOOKUP_DISALLOW_NON_WINDOWS_INTERNET_SID** is specified. |
| **LSA_LOOKUP_RETURN_LOCAL_NAMES** | Always returns local SAM account names even for Internet provider identities. |

### `Count` [in]

Specifies the number of SIDs in the *Sids* array. This is also the number of entries returned in the *Names* array. This value must be less than or equal to 20480.

### `Sids` [in]

Pointer to an array of SID pointers to look up. The SIDs can be well-known SIDs, user, group, or local group account SIDs, or domain SIDs.

### `ReferencedDomains` [out]

Receives a pointer to a pointer to a [LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list) structure. The **Domains** member of this structure is an array that contains an entry for each domain in which a SID was found. The entry for each domain contains the SID and flat name of the domain. For Windows domains, the flat name is the NetBIOS name. For links with non–Windows domains, the flat name is the identifying name of that domain, or it is **NULL**.

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory). This memory must be freed even when the function fails with the either of the error codes **STATUS_NONE_MAPPED** or **STATUS_SOME_NOT_MAPPED**

### `Names` [out]

Receives a pointer to an array of
[LSA_TRANSLATED_NAME](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_translated_name) structures. Each entry in the *Names* array contains the name information for the corresponding entry in the *Sids* array. For account SIDs, the **Name** member of each structure contains the isolated name of the account. For domain SIDs, the **Name** member is not valid.

The **DomainIndex** member of each entry in the *Names* array is the index of an entry in the **Domains** array returned in the *ReferencedDomains* parameter. The index identifies the **Domains** array for the domain in which the SID was found.

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory). This memory must be freed even when the function fails with the either of the error codes **STATUS_NONE_MAPPED** or **STATUS_SOME_NOT_MAPPED**

## Return value

If the function succeeds, the return value is one of the following **NTSTATUS** values.

| Return code | Description |
| --- | --- |
| **STATUS_SOME_NOT_MAPPED** | Some of the SIDs could not be translated. This is an informational-level return value. |
| **STATUS_SUCCESS** | All of the SIDs were found and successfully translated. |

If the function fails, the return value is an **NTSTATUS** code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NONE_MAPPED** | None of the SIDs were translated. This is an error-level return value. |
| **STATUS_TOO_MANY_SIDS** | The Sids array parameter was too large. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

The flag LSA_LOOKUP_PREFER_INTERNET_NAMES should be used for internet accounts such as MicrosoftAccount and Azure Active Directory accounts.
When this flag is specified then SID-Name lookup returns the UPN of the account in the form MicrosoftAccount\foo@outlook.com or AzureAD\foo@contoso.com.
For Microsoft Accounts both the local SAM SID and the internet SID result in the UPN being returned if this flag is specified.
If LSA_LOOKUP_PREFER_INTERNET_NAMES is not specified then for AAD accounts the NT4 style name of the form AzureAD\foo is returned. The NT4 style name is machine specific and its usage should be carefully evaluated and if possible should be avoided.
For MicrosoftAccounts if LSA_LOOKUP_PREFER_INTERNET_NAMES is not specified then the local SID of the account translates to the local SAM name, and the internet SID translates to the UPN name.

For account SIDs, the string returned in the **Name** member is the isolated name of the account (for example, user_name). If you need the composite name of the account (for example, Acctg\user_name), get the domain name from the *ReferencedDomains* buffer and append a backslash and the isolated name.

If the **LsaLookupSids2** function cannot translate a SID, the function uses the following algorithm:

1. If the SID's domain is known, the *ReferencedDomains* buffer contains an entry for the domain, and the string returned in the *Names* parameter is a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) representation of the account's relative identifier (RID) from the SID.
2. If the SID's domain is not known, the string returned in the *Names* parameter is a Unicode representation of the entire SID, and there is no domain record for this SID in the *ReferencedDomains* buffer.

In addition to looking up SIDs for local accounts, local domain accounts, and explicitly trusted domain accounts, **LsaLookupSids2** can look up SIDs for any account in any domain in the Windows forest, including SIDs that appear only in the **SIDhistory** field of an account in the forest. The **SIDhistory** field stores the former SIDs of an account that has been moved from another domain. To perform these searches, the function queries the global catalog of the forest.

## See also

[LSA_REFERENCED_DOMAIN_LIST](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_referenced_domain_list)

[LSA_TRANSLATED_NAME](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_translated_name)

[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy)