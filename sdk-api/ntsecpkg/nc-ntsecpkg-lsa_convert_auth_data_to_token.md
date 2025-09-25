# LSA_CONVERT_AUTH_DATA_TO_TOKEN callback function

## Description

The **ConvertAuthDataToToken** function creates an access token from the authorization data returned from the
[GetAuthDataForUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_auth_data_for_user) or
[GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data) functions.

## Parameters

### `UserAuthData` [in]

Pointer to the authorization data received from the
[GetAuthDataForUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_auth_data_for_user) or
[GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data) functions.

### `UserAuthDataSize` [in]

Size, in bytes, of the authorization data specified by the *UserAuthData* parameter.

### `ImpersonationLevel` [in]

A
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) value specifying the impersonation level for the token to be created.

### `TokenSource` [in]

Pointer to a
[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure specifying the source to record in the token.

### `LogonType` [in]

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value indicating the type of logon to record in the token.

### `AuthorityName` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that specifies the name of the authority that authorized this user, typically a domain name.

### `Token` [out]

Pointer to a HANDLE that receives the user token handle.

When you have finished using the user token, release the handle by calling [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

### `LogonId` [out]

Pointer to an [LUID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) that receives the [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) for the token.

### `AccountName` [out]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that receives the account name encoded in the *UserAuthData* parameter.

### `SubStatus` [out]

Pointer to a variable that receives additional information about the return value of the function call.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed.

## Remarks

A pointer to the **ConvertAuthDataToToken** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[GetAuthDataForUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_auth_data_for_user)

[GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string)