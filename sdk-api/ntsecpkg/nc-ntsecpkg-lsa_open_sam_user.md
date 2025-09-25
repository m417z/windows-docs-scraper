# LSA_OPEN_SAM_USER callback function

## Description

Retrieves a handle to a user account in the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) database.

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
| **SecNameAlternateId** | *Name* is in the AltSecId property of the SAM account. This value is used with the *Prefix* parameter. |
| **SecNameFlat** | *Name* is a flat [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN)–style account name. |
| **SecNameDN** | *Name* is the distinguished name of the object. For more information, see Remarks. |

### `Prefix` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that specifies the prefix to use with names that use a *NameType* of SecNameAlternateId.

### `AllowGuest` [in]

Specifies whether to use the Guest account if the SAM account is not found. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FALSE** | If the user is not found, the **OpenSamUser** function call fails. |
| **TRUE** | If the user is not found and the Guest account is enabled, the Guest account is used. |

### `Reserved` [in]

Reserved. Specify zero.

### `UserHandle` [out]

Pointer to a pointer that receives a handle to the user account.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is one of the following NTSTATUS error codes that indicates the reason for failure.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *NameType* is SecNameAlternateId and *Prefix* is **NULL**. |
| **STATUS_NO_SUCH_USER** | The SAM account could not be found. |

## Remarks

To close the handle received by the *UserHandle* parameter, call the
[CloseSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_close_sam_user) function.

The distinguished name of a user identifies the name, domain, and the complete path to the
[Active Directory](https://learn.microsoft.com/windows/desktop/AD/active-directory-domain-services) object that represents the user.

A pointer to the **OpenSamUser** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[CloseSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_close_sam_user)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)