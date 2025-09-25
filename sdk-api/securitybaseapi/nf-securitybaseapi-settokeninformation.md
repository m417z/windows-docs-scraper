# SetTokenInformation function

## Description

The **SetTokenInformation** function sets various types of information for a specified [access token](https://learn.microsoft.com/windows/win32/SecGloss/a-gly). The information that this function sets replaces existing information. The calling process must have appropriate access rights to set the information.

## Parameters

### `TokenHandle` [in]

A handle to the access token for which information is to be set.

### `TokenInformationClass` [in]

A value from the [TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-token_information_class) enumerated type that identifies the type of information the function sets from the *TokenInformation* parameter.

### `TokenInformation` [in]

A pointer to a buffer that contains the information set in the access token. The structure of this buffer depends on the type of information specified by the *TokenInformationClass* parameter.

### `TokenInformationLength` [in]

Specifies the length, in bytes, of the buffer pointed to by *TokenInformation*.

## Return value

If the function succeeds, the function returns a non-zero value.

If the function fails, it returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To set privilege information, an application can call the [AdjustTokenPrivileges](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function. To set a token's groups, an application can call the [AdjustTokenGroups](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups) function.

Token-type information can be set only when an access token is created.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/win32/SecAuthZ/access-control)

[AdjustTokenGroups](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[Basic Access Control Functions](https://learn.microsoft.com/windows/win32/SecAuthZ/authorization-functions)

[GetTokenInformation](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenProcessToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[OpenThreadToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_primary_group)