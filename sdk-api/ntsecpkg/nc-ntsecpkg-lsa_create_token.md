# LSA_CREATE_TOKEN callback function

## Description

The **CreateToken** function is used by SSP/APs to create tokens while processing calls to
[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn).

## Parameters

### `LogonId` [in]

Pointer to a logon session identifier for the new token. This identifier is obtained from a previous call to
[CreateLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_logon_session).

### `TokenSource` [in]

Pointer to a
[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure that specifies the source for this token. Specify the package name.

### `LogonType` [in]

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value that indicates the type of logon.

### `ImpersonationLevel` [in]

A
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) value that indicates the extent to which a server process can impersonate a client process.

### `TokenInformationType` [in]

Specifies the type of structure in the *TokenInformation* parameter.

| Value | Meaning |
| --- | --- |
| **LsaTokenInformationNull** | [LSA_TOKEN_INFORMATION_NULL](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_token_information_null) |
| **LsaTokenInformationV1** | [LSA_TOKEN_INFORMATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378721(v=vs.85)) |

### `TokenInformation` [in]

Pointer to the token information. The type of structure pointed to by *TokenInformation* is indicated by the *TokenInformationType* parameter.

If the structure pointed to by this parameter is an [LSA_TOKEN_INFORMATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378721(v=vs.85)) structure, the caller must allocate the memory for the **Groups** member of that structure by calling the [AllocatePrivateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_private_heap) function.

### `TokenGroups` [in]

Pointer to a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies groups not contained in *TokenInformation*.

### `AccountName` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This information is used for auditing and name searches.

### `AuthorityName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the authority that validated the logon [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), normally the Windows domain name.

### `Workstation` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the client's workstation, normally a NetBIOS name.

### `ProfilePath` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the path to the user's profile, if any.

### `Token` [out]

Pointer that receives the address of a handle to the new token. When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `SubStatus` [out]

Pointer to a variable that receives error information.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code that indicates the reason it failed.

## Remarks

A pointer to the **CreateToken** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)