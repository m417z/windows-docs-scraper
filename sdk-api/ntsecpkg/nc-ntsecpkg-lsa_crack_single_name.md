# LSA_CRACK_SINGLE_NAME callback function

## Description

The **CrackSingleName** function converts a name from one format to another.

## Parameters

### `FormatOffered` [in]

The format of the input name. The following table contains the valid values for this parameter.

| Value | Meaning |
| --- | --- |
| **DS_CANONICAL_NAME** | Complete canonical name (for example, example.microsoft.com/software/someone). The domain-only version includes a trailing forward slash (/). |
| **DS_CANONICAL_NAME_EX** | Same as DS_CANONICAL_NAME except that the rightmost forward slash (/) is replaced with a newline character (\n), even in a domain-only case (for example, example.microsoft.com/software\nsomeone). |
| **DS_DISPLAY_NAME** | A "friendly" display name. The display name is not necessarily the defining [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN). |
| **DS_FQDN_1779_NAME** | Fully qualified distinguished name (for example, CN=NameOfPerson,OU=Users,DC=Example,DC=Fabrikam,DC=Com). |
| **DS_NT4_ACCOUNT_NAME** | Windows account name (for example, Example\Name). The domain-only version includes trailing backslashes (\\). |
| **DS_SERVICE_PRINCIPAL_NAME** | Generalized [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (for example, www/www.microsoft.com@microsoft.com). |
| **DS_SID_OR_SID_HISTORY_NAME** | A [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) for the object. This can be either the current SID or a SID from the object's SID history. The SID string can use either the standard string representation of a SID, or one of the string constants defined in Sddl.h. For information about converting a binary SID into a SID string, see [SID Strings](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-strings). This value is not valid for the *formatDesired* parameter. |
| **DS_UNIQUE_ID_NAME** | GUID string that the [IIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iidfromstring) function returns (for example, {4fa050f0-f561-11cf-bdd9-00aa003a77b6}). |
| **DS_UNKNOWN_NAME** | Unknown name type. |
| **DS_USER_PRINCIPAL_NAME** | User principal name (for example, someone@example.microsoft.com). |

### `PerformAtGC` [in]

Specifies whether to perform the translation at a global catalog server.

### `NameInput` [in]

A pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name to convert.

### `Prefix` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that specifies a prefix for the name.

### `RequestedFormat` [in]

The requested format of the cracked name. For a list of valid values, see the *FormatOffered* parameter.

### `CrackedName` [out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that receives the reformatted name.

### `DnsDomainName` [out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that receives the name of the domain that owns the name specified by the *NameInput* parameter.

### `SubStatus` [out]

A pointer to a variable that receives additional information about the return value of the function call.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns STATUS_UNSUCCESSFUL. For more information, see the value returned in the *SubStatus* parameter.

## Remarks

A pointer to the **CrackSingleName** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)