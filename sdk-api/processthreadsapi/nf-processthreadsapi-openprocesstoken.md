# OpenProcessToken function

## Description

The **OpenProcessToken** function opens the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) associated with a process.

## Parameters

### `ProcessHandle` [in]

A handle to the process whose access token is opened. The process must have the PROCESS_QUERY_LIMITED_INFORMATION access permission. See [Process Security and Access Rights](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights) for more info.

### `DesiredAccess` [in]

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the requested types of access to the access token. These requested access types are compared with the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the token to determine which accesses are granted or denied.

For a list of access rights for access tokens, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `TokenHandle` [out]

A pointer to a handle that identifies the newly opened access token when the function returns.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To get a handle to an elevated process from within a non-elevated process, both processes must be started from the same account.

If the process being checked was started by a different account, the checking process needs to have the SE_DEBUG_NAME privilege enabled. See [Privilege Constants (Authorization)](https://learn.microsoft.com/windows/win32/secauthz/privilege-constants) for more info.

To close the access token handle returned through the *TokenHandle* parameter, call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[GetCurrentProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocesstoken)

[GetCurrentThreadEffectiveToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadeffectivetoken)

[GetCurrentThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadtoken)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)