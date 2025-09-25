# GetTokenInformation function

## Description

The **GetTokenInformation** function retrieves a specified type of information about an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The calling process must have appropriate access rights to obtain the information.

To determine if a user is a member of a specific group, use the
[CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership) function. To determine group membership for app container tokens, use the [CheckTokenMembershipEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembershipex) function.

## Parameters

### `TokenHandle` [in]

A handle to an access token from which information is retrieved. If *TokenInformationClass* specifies TokenSource, the handle must have TOKEN_QUERY_SOURCE access. For all other *TokenInformationClass* values, the handle must have TOKEN_QUERY access.

### `TokenInformationClass` [in]

Specifies a value from the
[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class) enumerated type to identify the type of information the function retrieves. Any callers who check the **TokenIsAppContainer** and have it return 0 should also verify that the caller token is not an identify level impersonation token. If the current token is not an app container but is an identity level token, you should return **AccessDenied**.

### `TokenInformation` [out, optional]

A pointer to a buffer the function fills with the requested information. The structure put into this buffer depends upon the type of information specified by the *TokenInformationClass* parameter.

### `TokenInformationLength` [in]

Specifies the size, in bytes, of the buffer pointed to by the *TokenInformation* parameter. If *TokenInformation* is **NULL**, this parameter must be zero.

### `ReturnLength` [out]

A pointer to a variable that receives the number of bytes needed for the buffer pointed to by the *TokenInformation* parameter. If this value is larger than the value specified in the *TokenInformationLength* parameter, the function fails and stores no data in the buffer.

If the value of the *TokenInformationClass* parameter is TokenDefaultDacl and the token has no default DACL, the function sets the variable pointed to by *ReturnLength* to `sizeof(`[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)`)` and sets the **DefaultDacl** member of the **TOKEN_DEFAULT_DACL** structure to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership)

[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_GROUPS_AND_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups_and_privileges)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)