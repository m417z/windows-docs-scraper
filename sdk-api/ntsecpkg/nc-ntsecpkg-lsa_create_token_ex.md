# LSA_CREATE_TOKEN_EX callback function

## Description

Creates tokens while processing calls to
[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn).

## Parameters

### `LogonId` [in]

A pointer to a logon session identifier for the new token. This identifier is obtained from a previous call to
[CreateLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_logon_session).

### `TokenSource` [in]

A pointer to a
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

A pointer to the token information. The type of structure pointed to by *TokenInformation* is indicated by the *TokenInformationType* parameter.

### `TokenGroups` [in]

A pointer to a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies groups not contained in *TokenInformation*.

### `Workstation` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the client's workstation, normally a NetBIOS name.

### `ProfilePath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the path to the user's profile, if any.

### `SessionInformation` [in]

Data that specifies information about the current logon session. The format of this data is specified by the value of the *SessionInformationType* parameter.

### `SessionInformationType` [in]

A value of the [SECPKG_SESSIONINFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-secpkg_sessioninfo_type) enumeration that specifies the format of the *SessionInformation* parameter. Currently, the only defined value is **SecSessionPrimaryCred**, which specifies that the value of the *SessionInformation* parameter is a [SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred) structure.

### `Token` [out]

A pointer that receives the address of a handle to the new token. When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `SubStatus` [out]

A pointer to a variable that receives error information.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code that indicates the reason it failed.

## Remarks

A pointer to the **CreateTokenEx** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)