# LSA_GET_AUTH_DATA_FOR_USER callback function

## Description

The **GetAuthDataForUser** function retrieves authentication information for a user from the Security Accounts Manager (SAM) database and puts it into a format suitable for the
[ConvertAuthDataToToken](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_convert_auth_data_to_token) function.

## Parameters

### `Name` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that specifies the name of the SAM account.

### `NameType` [in]

A
[SECPKG_NAME_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-secpkg_name_type) enumeration value that specifies the type of account name in *Name*. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SecNameSamCompatible** | *Name* is compatible with the SAM. An example of a name in SAM-compatible format is "ExampleDomain\Username". |
| **SecNameAlternateId** | *Name* is in the AltSecId property of the SAM account. You must specify a value for the *Prefix* parameter when using this value. |
| **SecNameFlat** | *Name* is a flat [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) style account name. |
| **SecNameDN** | *Name* is the distinguished name of the object. For more information, see Remarks. |

### `Prefix` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the prefix to use for names specified with the **SecNameAlternateId** *NameType*.

### `UserAuthData` [out]

Pointer that receives the address of the retrieved data.

### `UserAuthDataSize` [out]

Pointer to a **ULONG** that receives the size of the retrieved data.

### `UserFlatName` [out]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that receives the UPN, if applicable.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code that indicates the reason it failed.

## Remarks

The **GetAuthDataForUser** function combines the
[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user),
[GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data), and
[CloseSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_close_sam_user) functions into one call.

Pointers to these functions are available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[CloseSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_close_sam_user)

[GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)