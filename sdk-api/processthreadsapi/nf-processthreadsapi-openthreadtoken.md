# OpenThreadToken function

## Description

The **OpenThreadToken** function opens the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) associated with a thread.

## Parameters

### `ThreadHandle` [in]

A handle to the thread whose access token is opened.

### `DesiredAccess` [in]

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the requested types of access to the access token. These requested access types are reconciled against the token's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) to determine which accesses are granted or denied.

For a list of access rights for access tokens, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `OpenAsSelf` [in]

TRUE if the access check is to be made against the process-level [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

**FALSE** if the access check is to be made against the current security context of the thread calling the **OpenThreadToken** function.

The *OpenAsSelf* parameter allows the caller of this function to open the access token of a specified thread when the caller is impersonating a token at **SecurityIdentification** level. Without this parameter, the calling thread cannot open the access token on the specified thread because it is impossible to open executive-level objects by using the **SecurityIdentification** impersonation level.

### `TokenHandle` [out]

A pointer to a variable that receives the handle to the newly opened access token.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the token has the anonymous impersonation level, the token will not be opened and **OpenThreadToken** sets ERROR_CANT_OPEN_ANONYMOUS as the error.

## Remarks

Tokens with the anonymous impersonation level cannot be opened.

Close the access token handle returned through the *TokenHandle* parameter by calling
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[GetCurrentThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadtoken)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)