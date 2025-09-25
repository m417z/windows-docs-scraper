# DuplicateToken function

## Description

The **DuplicateToken** function creates a new [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that duplicates one already in existence.

## Parameters

### `ExistingTokenHandle` [in]

A handle to an access token opened with TOKEN_DUPLICATE access.

### `ImpersonationLevel` [in]

Specifies a
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumerated type that supplies the impersonation level of the new token.

### `DuplicateTokenHandle` [out]

A pointer to a variable that receives a handle to the duplicate token. This handle has TOKEN_IMPERSONATE and TOKEN_QUERY access to the new token.

When you have finished using the new token, call the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the token handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DuplicateToken** function creates an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), which you can use in functions such as [SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken) and [ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser). The token created by **DuplicateToken** cannot be used in the [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, which requires a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). To create a token that you can pass to **CreateProcessAsUser**, use the [DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) function.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex)

[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken)